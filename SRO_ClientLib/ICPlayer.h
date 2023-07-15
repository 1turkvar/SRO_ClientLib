#pragma once

class CICPlayer {
	virtual void* GetType();
	virtual void* GetParentType();
	virtual ~CICPlayer();

	char cobjchild_padding[2144];
public:
	char level;
	long long exp_current;
	int skill_exp;
	char gap_cicplayer[4];
	int skillpoints;
	char gap87C[6292];
};

#define g_CICPlayer (*((CICPlayer**)0x00EEF5EC)) // Blackroque = 00E71040
