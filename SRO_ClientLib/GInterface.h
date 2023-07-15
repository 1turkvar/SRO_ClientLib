#pragma once
#include "stdafx.h"
#include "IRMManager.h"

#define CLIENT_SCREEN_WIDTH (*(int*)0x00ED7CB8)
#define CLIENT_SCREEN_HEIGHT (*(int*)0x00ED7CBC)

enum eLogType : int
{
	SYSLOG_NONE = 0,
	SYSLOG_ERR = 4,
	SYSLOG_GUIDE = 6
};

class CGInterface
{
public:
	CIRMManager m_IRM; //0x036C

public:
	static CGInterface* GetInterface();
	class CIFMainPopup* GetMainPopup();
	void ShowPinkNotify(std::wstring& msg);
	void ShowBlueNotify(std::wstring& msg);
	void ShowGreenNotify(std::wstring& msg);
	void WriteSystemMessage(eLogType level, const wchar_t* str);
	void SwitchQuestWindow();
	void SwitchGameGuide();
};

#define g_pCGInterface (*(CGInterface**)0x0110F80C)