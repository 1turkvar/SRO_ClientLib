// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once
using namespace std;

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _CRT_SECURE_NO_WARNINGS			// Disable warning when using unsafe functions
#define _DEBUG_

#if !defined(SRO_ClIENT_ASM_DECL)
#define SRO_ClIENT_ASM_DECL static __declspec(naked) void
#endif

typedef unsigned char byte;
typedef unsigned char uint;

#include "targetver.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <stdint.h>
#include <string>
#include <functional>
#include <map>
#include <sstream>
#include <Windows.h>
#include <stdio.h>
#include <cmath>
