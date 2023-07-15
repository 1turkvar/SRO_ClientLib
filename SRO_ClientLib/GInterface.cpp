#include "GInterface.h"
#include "IFMainPopup.h"
#include "wstring05.h"
#include "Globals.h"


CGInterface* CGInterface::GetInterface(void)
{
	return *reinterpret_cast<CGInterface**>(0x0110F80C);
}

CIFMainPopup* CGInterface::GetMainPopup(void)
{
	return reinterpret_cast<CIFMainPopup * (__thiscall*)(CGInterface*)>(0x00798D00)(this);
}


void CGInterface::ShowPinkNotify(std::wstring& msg)
{
	wstring05 noobstring(msg.c_str());
	reinterpret_cast<void(__thiscall*)(CGInterface*, std::wstring*)>(0x00777BF0)(this, reinterpret_cast<std::wstring*>(&noobstring));
}

void CGInterface::ShowBlueNotify(std::wstring& msg)
{
	wstring05 noobstring(msg.c_str());
	reinterpret_cast<void(__thiscall*)(CGInterface*, std::wstring*)>(0x0077B580)(this, reinterpret_cast<std::wstring*>(&noobstring));
}

void CGInterface::ShowGreenNotify(std::wstring& msg)
{
	wstring05 noobstring(msg.c_str());
	reinterpret_cast<void(__thiscall*)(CGInterface*, std::wstring*)>(0x0077B5B0)(this, reinterpret_cast<std::wstring*>(&noobstring));
}

// CGInterface::WriteSystemMessage(int,wchar_t *) .text 007781B0 00000053 00000008 00000008 R . . . . . .
void CGInterface::WriteSystemMessage(eLogType level, const wchar_t* str) {
	reinterpret_cast<void(__thiscall*)(CGInterface*, eLogType, const wchar_t*)>(0x007781B0)(this, level, str);
}

void CGInterface::SwitchQuestWindow()
{
	return reinterpret_cast<void(__thiscall*)(CGInterface*)>(0x007990E0)(this);
}

void CGInterface::SwitchGameGuide()
{
	return reinterpret_cast<void(__thiscall*)(void*)>(0x0079F690)(this);
}
