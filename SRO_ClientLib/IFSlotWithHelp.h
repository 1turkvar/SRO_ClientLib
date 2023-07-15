#pragma once
#include "SOItem.h"

class CIFSlotWithHelp
{
	char pad_0000[912]; //0x0000
	CSOItem* _CSOItem; //0x0390

public:
	void AppendAdvancedInfo(class CIFHelperBubbleWindow* window);
};