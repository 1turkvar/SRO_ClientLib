#pragma once
#include "stdafx.h"
#include "Vec3.h"

class Keyframe
{
public:
	float time; //0x0000 
	Vec3 position; //0x0004 
	Vec3 rotation; //0x0010 
	float distance; //0x001C 

};//Size=0x0020