#pragma once
#include "stdafx.h"
#include "IFHelperBubbleWindow.h"
#include "IFSlotWithHelp.h"

class OldItemTooltip
{
public:
	OldItemTooltip(bool Sys);
	void AppendToolTip(CIFHelperBubbleWindow* ecx);
	void ReadSunInfoText(wchar_t* text);
private:

};