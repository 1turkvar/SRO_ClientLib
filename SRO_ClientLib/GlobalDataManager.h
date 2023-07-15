#pragma once
#include "LevelData.h"

class CGlobalDataManager {
public:
	CLevelData* GetLevelData(int level);

	static CGlobalDataManager* GetGlobalDataManager();
	class ObjectData* GetObjectData(unsigned int ObjID);

};


#define g_CGlobalDataManager ((CGlobalDataManager*)0x00EEDF08)
