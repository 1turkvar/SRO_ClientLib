#pragma once
#include "stdafx.h"

typedef void (*static_constructor)(void);
int client_override_constructor(int id, void (*function)(void));