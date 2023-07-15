#include "OldUnderBar.h"
#include "IFUnderMenuBar.h"
#include "MemoryHack.h"

MemoryHack* _MemOldUnderBar = new MemoryHack();

const DWORD OldUnderBarFuckAdder = 0x00D9841C;

OldUnderBar::OldUnderBar(bool SysOpen)
{
	if (SysOpen == true)
	{
		_MemOldUnderBar->replaceAddr(OldUnderBarFuckAdder, _MemOldUnderBar->addr_from_this(&CNIFUnderMenuBar::Update));
	}

}