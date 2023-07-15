#include "IRMManager.h"

CIRMManager::CIRMManager() {
    N00009CBC = 0;
}

CIFWnd* CIRMManager::GetResObj(int id, int a2) {
    return reinterpret_cast<CIFWnd * (__thiscall*)(CIRMManager*, int, int)>(0x008B51F0)(this, id, a2);
}
