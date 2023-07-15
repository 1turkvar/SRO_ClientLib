#include "GlobalDataManager.h"
#include "ObjectData.h"

CLevelData* CGlobalDataManager::GetLevelData(int level) {
	return ((CLevelData * (__thiscall*)(CGlobalDataManager * pthis, int level))0x00937F20)(this, level);
}

CGlobalDataManager* CGlobalDataManager::GetGlobalDataManager()
{
	return reinterpret_cast<CGlobalDataManager*>(0x00EEDF08);
}

ObjectData* CGlobalDataManager::GetObjectData(unsigned int ObjID)
{
	return reinterpret_cast<ObjectData * (__thiscall*)(CGlobalDataManager*, unsigned int)>(0x0093F710)(this, ObjID);
}