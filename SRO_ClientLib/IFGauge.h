#pragma once

#include "IFStatic.h"

class CNIFGauge : public CNIFStatic { // 928
public:
	float background_value;
	float foreground_value;
	char pad[48];
};
