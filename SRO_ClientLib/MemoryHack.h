#pragma once
#include "stdafx.h"

class MemoryHack
{
public:
	MemoryHack();
	~MemoryHack();

	static void* AddPtr(void* ptr, intptr_t offset);
	static const void* AddPtr(const void* ptr, intptr_t offset);
	template<typename T>
	inline static T& RefPtr(uintptr_t ptr)
	{
		return *reinterpret_cast<T*>(ptr);
	}
	template<typename T>
	inline static const T& RefPtr(const void* ptr, intptr_t offset)
	{
		return *static_cast<const T*>(AddPtr(ptr, offset));
	}
	template<typename T>
	inline static T& RefPtr(void* ptr, intptr_t offset)
	{
		return *static_cast<T*>(AddPtr(ptr, offset));
	}
	static __declspec(noinline) void AppMark(const char* ptr);

	static bool UnProtect(void* addr, size_t count);
	static bool ReProtect();
	static bool Detour(bool jmpOrCall, void* source, void* dest);
	static bool Nop(void* addr, size_t count);
	static bool Write(void* addr, void* data, uint32_t count);
	static bool Read(void* source, void* dest, uint32_t count);

	void WriteNumber(DWORD d_offset, DWORD d_val, DWORD d_max, DWORD d_offsetlen);
	void WriteByte(DWORD d_offset, DWORD d_byte);
	void WriteString(DWORD d_offset, char* s_val);
	void Write(DWORD d_offset, BYTE s_val);
	void SetNop(DWORD d_offset, int nLength);
	void Retn(DWORD d_offset);
	void RetnVal(DWORD d_offset, byte nValue);
	void Jnz(DWORD dwOffset, DWORD dwAddress);
	void Jmp(DWORD dwOffset, DWORD dwAddress);

	static bool CopyBytes(uintptr_t dst, const void* src, size_t size);
	static bool CopyBytes(void* dst, const void* src, size_t size);

	static bool Hook(uintptr_t addr, const void* jumpTo, size_t len, bool JMPt_or_CALLf = false);
	static bool Hook(void* addr, const void* jumpTo, size_t len, bool JMPt_or_CALLf = false);



	template<typename T>
	int addr_from_this(T funptr) {
		union {
			int addr;
			T ptr;
		} myu;

		myu.ptr = funptr;
		return myu.addr;
	}

	/*Hook*/
	template<typename T>
	void placeHook(int trampoline_location, T& target_location)
	{
		placeHook(trampoline_location, reinterpret_cast<int>(&target_location));
	}

	void placeHook(int trampoline_location, int target_location);

	void replaceOffset(int trampoline_location, int target_location);

	void replaceAddr(int addr, int value);

	void vftableHook(unsigned int vftable_addr, int offset, int target_func);

private:
	static void* m_tmpProtectAddr;
	static DWORD m_tmpProtect;
	static size_t m_tmpProtectSize;

	HANDLE cur_process;
};