#include "OldMainPopWnd.h"
#include "GInterface.h"
#include "MemoryHack.h"
#include "Globals.h"

MemoryHack* _MemOldMainPop = new MemoryHack();

const DWORD Old_MainPopFuncAdder = 0x006A28FF;
const DWORD Old_MainPopFuncAdderJmpBack = 0x006A298C;

const DWORD OldMainPopSendKey = 0x006A2540;
const DWORD OldMainPopSendKeyJmpBack = 0x006A2547;

const DWORD Old_MainpopPosFix = 0x006A234B;
const DWORD Old_MainpopPosFixJumpBack = 0x006A2353;

__declspec(naked) void ASM_OldMainPop()
{
	__asm
	{
		mov ecx, dword ptr ds : [esi + 0x7BC] ;
		mov edx, dword ptr ds : [ecx] ;
		mov eax, dword ptr ds : [edx + 0x50] ;
		call eax;
		mov eax, dword ptr ss : [esp + 0x2C] ;
		cmp eax, 0x8;
		jmp Old_MainPopFuncAdderJmpBack;
	}
}

__declspec(naked) void ASM_QuestSendQ()
{
	__asm
	{
		pushad;
		pushfd;
		call CGInterface::SwitchQuestWindow; //Quest Açýlýr.
		popfd;
		popad;
		jmp OldMainPopSendKeyJmpBack;
	}
}

//__declspec(naked) void ASM_CharacterPosFix()
//{
//	__asm
//	{
//		mov eax, dword ptr ds : [edx + 0x98] ;
//		push PosW;
//		jmp Old_MainpopPosFixJumpBack;
//	}
//}


OldMainPopWnd::OldMainPopWnd(bool Sys)
{
	if (Sys == true)
	{
		_MemOldMainPop->Detour(false, reinterpret_cast<void*>(Old_MainPopFuncAdder), ASM_OldMainPop);
		_MemOldMainPop->Detour(false, reinterpret_cast<void*>(OldMainPopSendKey), ASM_QuestSendQ);
		//_MemOldMainPop->Detour(false, reinterpret_cast<void*>(Old_MainpopPosFix), ASM_CharacterPosFix);
	}
}
