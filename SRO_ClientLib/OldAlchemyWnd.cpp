#include "OldAlchemyWnd.h"
#include "MemoryHack.h"

MemoryHack* _MemOldAlchemyPatch = new MemoryHack();

const DWORD OnCreateInsideCall = 0x00BA20B0;
const DWORD OnCreateJumpBack = 0x00479B72;

const char* NormalIconPath = "interface\\ifcommon\\com_windowclose.ddj";
const char* AlchemyIconPath = "interface\\alchemy\\alcm_windowclose.ddj";
char* AlchemyIcon = strdup("icon\\alchemy.ddj");

__declspec(naked) void asmAlchemyCloseButton()
{
	__asm
	{
		CMP[esi + 0x34], 168;
		jne not_alchemy;
		MOV DWORD PTR SS : [ESP + 0x34] , 0x0F;
		jmp done;
	not_alchemy:
		MOV DWORD PTR SS : [ESP + 0x34] , 0x0A;
	done:
		MOV DWORD PTR SS : [ESP + 0x3C] , EAX;
		CALL OnCreateInsideCall;
		ADD ESP, 0x14;
		MOV DWORD PTR DS : [ESI + 0x794] , EAX;
		XOR EAX, EAX;
		PUSH EAX;
		PUSH EAX;
		SUB ESP, 0x1C;
		MOV ECX, ESP;
		MOV DWORD PTR SS : [ESP + 0x3C] , ESP;
		PUSH 0x26;
		MOV DWORD PTR DS : [ECX + 0x18] , 0x0F;
		MOV DWORD PTR DS : [ECX + 0x14] , EAX;
		CMP[esi + 0x34], 168;
		jne not_alchemy_2;
		PUSH[AlchemyIconPath];
		jmp done_2;
	not_alchemy_2:
		PUSH[NormalIconPath];
	done_2:
		JMP OnCreateJumpBack;
	}
}

OldAlchemyWnd::OldAlchemyWnd(bool Sys)
{
	if (Sys == true)
	{
		_MemOldAlchemyPatch->Detour(false, reinterpret_cast<void*>(0x00479B3A), asmAlchemyCloseButton);

		_MemOldAlchemyPatch->WriteString(0x00D7F29A, AlchemyIcon);
		/*0x00574389*/
		_MemOldAlchemyPatch->Write(0x00574389 + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x00574389 + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x00574389 + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x00574389 + 4, 0x00);
		/*0x00574CC8*/
		_MemOldAlchemyPatch->Write(0x00574CC8 + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x00574CC8 + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x00574CC8 + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x00574CC8 + 4, 0x00);
		/*0x0057510C*/
		_MemOldAlchemyPatch->Write(0x0057510C + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x0057510C + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x0057510C + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x0057510C + 4, 0x00);
		/*0x0057584C*/
		_MemOldAlchemyPatch->Write(0x0057584C + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x0057584C + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x0057584C + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x0057584C + 4, 0x00);
		/*0x00577159*/
		_MemOldAlchemyPatch->Write(0x00577159 + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x00577159 + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x00577159 + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x00577159 + 4, 0x00);
		/*0x00578005*/
		_MemOldAlchemyPatch->Write(0x00578005 + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x00578005 + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x00578005 + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x00578005 + 4, 0x00);
		/*0x0057871B*/
		_MemOldAlchemyPatch->Write(0x0057871B + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x0057871B + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x0057871B + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x0057871B + 4, 0x00);
		/*0x0057A89C*/
		_MemOldAlchemyPatch->Write(0x0057A89C + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x0057A89C + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x0057A89C + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x0057A89C + 4, 0x00);
		/*0x0059C98A*/
		_MemOldAlchemyPatch->Write(0x0059C98A + 1, 0x9A);
		_MemOldAlchemyPatch->Write(0x0059C98A + 2, 0xF2);
		_MemOldAlchemyPatch->Write(0x0059C98A + 3, 0xD7);
		_MemOldAlchemyPatch->Write(0x0059C98A + 4, 0x00);
	}
}
