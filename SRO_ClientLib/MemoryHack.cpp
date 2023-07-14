#include "MemoryHack.h"

void* MemoryHack::m_tmpProtectAddr;
DWORD MemoryHack::m_tmpProtect;
size_t MemoryHack::m_tmpProtectSize;

MemoryHack::MemoryHack()
{
	this->cur_process = GetCurrentProcess();
}

MemoryHack::~MemoryHack()
{
	printf("memory::memory constructor -> GetCurrentProcess failed\n");
	this->cur_process = (HANDLE)-1;
}

void* MemoryHack::AddPtr(void* ptr, intptr_t offset)
{
	return static_cast<char*>(ptr) + offset;
}

const void* MemoryHack::AddPtr(const void* ptr, intptr_t offset)
{
	return static_cast<const char*>(ptr) + offset;
}

void MemoryHack::AppMark(const char* text)
{
	if (text == nullptr)
		__debugbreak();
}

bool MemoryHack::UnProtect(void* addr, size_t count)
{
	if (VirtualProtect(addr, count, PAGE_READWRITE, &m_tmpProtect) == FALSE)
		return false;

	m_tmpProtectAddr = addr;
	m_tmpProtectSize = count;

	return true;
}

bool MemoryHack::ReProtect()
{
	//restore original protection mode
	return VirtualProtect(m_tmpProtectAddr, m_tmpProtectSize, m_tmpProtect, &m_tmpProtect) != FALSE;
}

void MemoryHack::Write(DWORD d_offset, BYTE s_val)
{
	DWORD oldProtect;
	void* addr = reinterpret_cast<void*>(d_offset);
	if (VirtualProtect(addr, 1, PAGE_READWRITE, &oldProtect) == FALSE)
	{
		throw std::runtime_error("cannot patch expbar function");
		return;
	}
	*reinterpret_cast<BYTE*>(addr) = s_val;
	VirtualProtect(addr, 1, oldProtect, &oldProtect);
}

//false = jmp
//true = call
bool MemoryHack::Detour(bool jmpOrCall, void* source, void* dest)
{
#pragma pack(push, 1)
	struct
	{
		uint8_t opcode;
		uintptr_t addr;
	}	*instr = static_cast<decltype(instr)>(source);
#pragma pack(pop)

	const size_t instrSize = sizeof(*instr);

	if (!UnProtect(source, instrSize))
		return false;

	instr->opcode = (jmpOrCall == false) ? 0xE9 : 0xE8;
	instr->addr = reinterpret_cast<uintptr_t>(dest) - (reinterpret_cast<uintptr_t>(source) + 5);

	//restore original memory protection mode
	return ReProtect();
}

bool MemoryHack::Nop(void* addr, size_t count)
{
	if (!UnProtect(addr, count))
		return false;


	std::memset(addr, 0x90, count);

	//restore original memory protection mode
	return ReProtect();
}

bool MemoryHack::Write(void* addr, void* data, uint32_t count)
{
	if (!UnProtect(addr, count))
		return false;

	std::memcpy(addr, data, count);

	//restore original memory protection mode
	return ReProtect();
}

bool MemoryHack::Read(void* source, void* dest, uint32_t count)
{
	if (!UnProtect(source, count))
		return false;

	std::memcpy(dest, source, count);

	//restore original memory protection mode
	return ReProtect();
}

//write decimal number
void MemoryHack::WriteNumber(DWORD d_offset, DWORD d_val, DWORD d_max, DWORD d_offsetlen)
{
	if (d_val > d_max) return;
	WriteProcessMemory(this->cur_process, (LPVOID)d_offset, &d_val, d_offsetlen, NULL);
}

void MemoryHack::WriteByte(DWORD d_offset, DWORD d_byte)
{
	WriteProcessMemory(this->cur_process, (LPVOID)d_offset, &d_byte, 1, NULL);
}


void MemoryHack::WriteString(DWORD d_offset, char* s_val)
{
	long nLen = strlen(s_val);
	for (long i = 0; i < nLen; i++)
	{
		char chr = INT(s_val[i]);
		DWORD n_offset = d_offset + i;
		WriteProcessMemory(this->cur_process, (LPVOID)n_offset, &chr, 1, NULL);
	}
}

bool MemoryHack::CopyBytes(uintptr_t dst, const void* src, size_t size)
{
	return CopyBytes(reinterpret_cast<void*>(dst), src, size);
}

bool MemoryHack::CopyBytes(void* dst, const void* src, size_t size)
{
	DWORD oldProtect;
	if (VirtualProtect(dst, size, PAGE_READWRITE, &oldProtect) == FALSE)
		return false;
	memcpy(dst, src, size);
	if (VirtualProtect(dst, size, oldProtect, &oldProtect) == FALSE)
		return false;
	return true;
}

bool MemoryHack::Hook(uintptr_t addr, const void* jumpTo, size_t len, bool JMPt_or_CALLf)
{
	return Hook(reinterpret_cast<void*>(addr), jumpTo, len, JMPt_or_CALLf);
}

bool MemoryHack::Hook(void* addr, const void* jumpTo, size_t len, bool JMPt_or_CALLf)
{
#pragma pack(push, 1)
	struct
	{
		uint8_t opcode;
		uint32_t offset;
	} *ins = static_cast<decltype(ins)>(addr);
#pragma pack(pop)
	const size_t instructionSize = sizeof(*ins);
	if (len < instructionSize)
		return false;
	DWORD oldProtect;
	if (VirtualProtect(ins, len, PAGE_READWRITE, &oldProtect) == FALSE)
		return false;
	ins->opcode = JMPt_or_CALLf ? 0xE9 : 0xE8;
	ins->offset = (uint32_t)((uintptr_t)jumpTo - (uintptr_t)addr - instructionSize);
	std::memset(MemoryHack::AddPtr(ins, instructionSize), 0x90, len - instructionSize);
	VirtualProtect(ins, len, oldProtect, &oldProtect);
	return true;
}

void MemoryHack::Retn(DWORD dwOffset)
{
	byte retn = 0xC3;
	WriteProcessMemory(this->cur_process, (LPVOID)dwOffset, &retn, 1, NULL);
}

void MemoryHack::RetnVal(DWORD dwOffset, byte nValue)
{
	//0xC2 0x04 0x00 = retn in this case, [retn %d]
	byte buf[] = { 0xC2, nValue, 0x00 };
	int size = sizeof(buf) / sizeof(buf[0]);
	WriteProcessMemory(this->cur_process, (LPVOID)dwOffset, &buf, size, NULL);
}

void MemoryHack::Jnz(DWORD dwOffset, DWORD dwAddress)
{
	byte jnzInstruction[] = { 0x0F, 0x85 };
	WriteProcessMemory(this->cur_process, (LPVOID)dwOffset, &jnzInstruction, 2, NULL);
	WriteProcessMemory(this->cur_process, (LPVOID)(dwOffset + 2), &dwAddress, sizeof(DWORD), NULL);
}

void MemoryHack::Jmp(DWORD dwOffset, DWORD dwAddress)
{
	byte jmpInstruction = 0xE9;
	this->Write(dwOffset, 0xE9);
	this->WriteNumber(dwOffset + 1, dwAddress, 999999999, sizeof(DWORD));
	WriteProcessMemory(this->cur_process, (LPVOID)(dwOffset + 1), &dwAddress, 4, NULL);
}

void MemoryHack::SetNop(DWORD d_offset, int nLength)
{
	unsigned char nop = 0x90;
	for (int i = 0; i < nLength; i++) //nlen + 1 ?
	{
		DWORD dCurOffset = (d_offset + i);
		WriteProcessMemory(this->cur_process, (LPVOID)dCurOffset, &nop, 1, NULL);
	}
}

/*Hook*/
void MemoryHack::placeHook(int trampoline_location, int target_location)
{

	//char jmp_inst[] = { 0xE9, 0x00, 0x00, 0x00, 0x00 };
	uint8_t jmp_inst[] = { 0xE9, 0x00, 0x00, 0x00, 0x00 };
	int distance;
	DWORD dwProtect = 0;

	distance = target_location - trampoline_location - 5;

	// Write jump-distance to instruction
	memcpy((jmp_inst + 1), &distance, 4);

	if (!VirtualProtect((LPVOID)trampoline_location, sizeof(jmp_inst), PAGE_EXECUTE_READWRITE, &dwProtect)) {
		perror("Failed to unprotect memory\n");
		return;
	}

	memcpy((LPVOID)trampoline_location, jmp_inst, sizeof(jmp_inst));

	VirtualProtect((LPVOID)trampoline_location, sizeof(jmp_inst), dwProtect, NULL);

}

void MemoryHack::replaceOffset(int trampoline_location, int target_location)
{

	char inst_offset[] = { 0x00, 0x00, 0x00, 0x00 };
	int distance;
	DWORD dwProtect = 0;

	int offset_location = trampoline_location + 1;

	distance = target_location - trampoline_location - 5;

	// Write jump-distance to instruction
	memcpy(inst_offset, &distance, 4);

	if (!VirtualProtect((LPVOID)offset_location, sizeof(inst_offset), PAGE_EXECUTE_READWRITE, &dwProtect)) {
		perror("Failed to unprotect memory\n");
		return;
	}

	memcpy((LPVOID)offset_location, inst_offset, sizeof(inst_offset));

	VirtualProtect((LPVOID)offset_location, sizeof(inst_offset), dwProtect, NULL);

}

void MemoryHack::replaceAddr(int addr, int value)
{
	DWORD dwProtect;

	if (!VirtualProtect((LPVOID)addr, sizeof(int), PAGE_EXECUTE_READWRITE, &dwProtect)) {
		perror("Failed to unprotect memory\n");
		return;
	}

	*((int*)addr) = value;

	VirtualProtect((LPVOID)addr, sizeof(int), dwProtect, NULL);
}

void MemoryHack::vftableHook(unsigned int vftable_addr, int offset, int target_func)
{
	MemoryHack::replaceAddr(vftable_addr + offset * sizeof(void*), target_func);
}

