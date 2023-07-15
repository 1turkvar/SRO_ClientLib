#include "OldItemTooltip.h"
#include "MemoryHack.h"

MemoryHack* _MemTooltipPatch = new MemoryHack();

std::wstring LastSunInfoText;
bool SunInfoResetted;

const DWORD dwSunInfoTextJmpback = 0x0066FC69;
const DWORD dwSunInfoTextCall = 0x0047E880;

__declspec(naked) void asmSunInfoText()
{
	__asm
	{
		pushad;
		pushfd;
		push eax;
		call OldItemTooltip::ReadSunInfoText;
		popfd;
		popad;
		call dwSunInfoTextCall;
		jmp dwSunInfoTextJmpback;
	}
}

const DWORD dwSunInfoJmpback = 0x0066FA67;
__declspec(naked) void asmAppendSunInfo()
{
	_asm push 0xD09787;
	SunInfoResetted = false;
	_asm jmp dwSunInfoJmpback;
}



const DWORD dwToolTipJmpback = 0x0066E135;
const DWORD dwAppendOldToolTipCall = 0x00776D20;
__declspec(naked) void asmAppendOldToolTip()
{
	__asm
	{
		call dwAppendOldToolTipCall;
		pushad;
		pushfd;
		push ebp;
		call OldItemTooltip::AppendToolTip;
		popfd;
		popad;
		jmp dwToolTipJmpback;
	}
}


void OldItemTooltip::AppendToolTip(CIFHelperBubbleWindow* ecx)
{
	if (SunInfoResetted)
	{
		if (LastSunInfoText.length() > 0)
		{
			std::wstring empty = L"";
			ecx->WriteLine(empty, 0, 0xFFffd953, 0, 3);
			ecx->WriteLine(LastSunInfoText, 0, 0xFFffd953, 0, 3);
			SunInfoResetted = false;
		}
	}
}

void OldItemTooltip::ReadSunInfoText(wchar_t* text)
{
	SunInfoResetted = true;
	LastSunInfoText = std::wstring(text);
}


OldItemTooltip::OldItemTooltip(bool Sys)
{
	if (Sys == true)
	{
		uint8_t AdvancedElixirSocketPatch[6] = { 0xE9, 0xC5, 0x00, 0x00, 0x00, 0x90 };
		_MemTooltipPatch->CopyBytes(0x0066FDB0, AdvancedElixirSocketPatch, sizeof(AdvancedElixirSocketPatch));
		_MemTooltipPatch->SetNop(0x0066FC69, 27);
		_MemTooltipPatch->Hook(0x0066FC64, asmSunInfoText, 5, true);
		_MemTooltipPatch->Hook(0x0066E130, asmAppendOldToolTip, 5, true);
		_MemTooltipPatch->Hook(0x0066FA62, asmAppendSunInfo, 5, true);
	}
}
