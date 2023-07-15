#include "OldTargetWnd.h"
#include "MemoryHack.h"

MemoryHack* _MemOldTargetWnd = new MemoryHack();

#define IS_BIONIC(tid) ((tid & 2) == (2))
#define CHECK_TID1(tid, comp) ((tid & (7 << 2)) == (comp << 2))
#define CHECK_TID2(tid, comp) ((tid & (3 << 5)) == (comp << 5))
#define CHECK_TID3(tid, comp) ((tid & (15 << 7)) == (comp << 7))
#define CHECK_TID4(tid, comp) ((tid & (31 << 11)) == (comp << 11))


static char latest_used_gem[256];
static char unk00[32];
static wchar_t lvl_nop[32];

void __stdcall DrawCICMonsterGem(const char* str)
{
	strcpy(latest_used_gem, str);
}

__declspec(naked) void asmDrawCICMonsterGem()
{
	static DWORD retn_addr;
	__asm
	{
		pop retn_addr

		push ecx
		push dword ptr ss : [esp + 4]
		call DrawCICMonsterGem
		pop ecx

		mov eax, 0x00414FB0
		call eax

		push retn_addr
		retn
	}
}

BOOL __fastcall IsMonster(DWORD* pTid)
{
	WORD tid = *pTid;
	if (!IS_BIONIC(tid) || !CHECK_TID1(tid, 1) || !CHECK_TID2(tid, 2) || !CHECK_TID3(tid, 1) || !CHECK_TID4(tid, 1))
	{
		return FALSE;
	}
	return TRUE;
}


OldTargetWnd::OldTargetWnd(bool SysOpen)
{
	if (SysOpen == true)
	{
		strcpy(latest_used_gem, "interface\\targetwindow\\tw_gem_normal.ddj");
		lvl_nop[0] = '\0';
		unk00[0] = '\0';

		char* ptr = latest_used_gem;
		_MemOldTargetWnd->CopyBytes(0x0069A071 + 1, &ptr, 4);

		BYTE patch[] = { 0x83, 0xF8, 0x00, 0x0F, 0x84, 0x4C, 0x07, 0x00, 0x00 };
		_MemOldTargetWnd->CopyBytes(0x006997A9, patch, 9);

		_MemOldTargetWnd->Hook(0x00699744, asmDrawCICMonsterGem, 5);

		_MemOldTargetWnd->Hook(0x0069A02A, IsMonster, 5);

		ptr = unk00;
		uint32_t val = (uint32_t)&lvl_nop;
		_MemOldTargetWnd->CopyBytes(0x0069BA08 + 1, &val, 4);
	}
}
