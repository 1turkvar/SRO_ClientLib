#pragma once
#include "stdafx.h"


class DataBank
{
public:
	DataBank();
	~DataBank();

#pragma region PatchClient Data
	byte _CAP;
	//Level Cap
	DWORD _LevelCapOffset;
	byte _LevelCap;
	DWORD _MaxDGOffset;
	byte _MaxDGCount;
	//Party Matching Cap
	DWORD _PartyMatchingOffset_1;
	DWORD _PartyMatchingOffset_2;
	DWORD _PartyMatchingOffset_3;
	DWORD _PartyMatchingOffset_4;
	DWORD _PartyMatchingOffset_5;
	DWORD _PartyMatchingOffset_6;
	DWORD _PartyMatchingOffset_7;
	DWORD _PartyMatchingOffset_8;
	byte _PartyCap;
	//Max Skill
	DWORD _SkillCapOffset;
	byte _SkillCap;
	//Max Quest
	DWORD _QuestCapOffset;
	byte _QuestCap;
	//Max Character
	DWORD _MaxCharacterOffet;
	byte _MaxCharacterCout;
	//Mastery Max Limit
	DWORD _MaxLevepUpMastery;
	byte _MaxLevepUpCap;
	DWORD _MaxMasteryLimitOffset_CH_1;
	DWORD _MaxMasteryLimitOffset_CH_2;
	DWORD _MaxMasteryLimitOffset_CH_1_1;
	DWORD _MaxMasteryLimitOffset_CH_1_2;
	byte _MaxMasteryCHCount_1;
	byte _MaxMasteryCHCount_2;
	DWORD _MaxMasteryLimitOffset_EU_1;
	DWORD _MaxMasteryLimitOffset_EU_2;
	DWORD _MaxMasteryLimitOffset_EU_3;
	DWORD _MaxMasteryLimitOffset_EU_4;
	byte _MaxMasteryEUCap;
	//Guild-Union Chat Limit
	DWORD _UnionChatLimitOffset;
	byte _UnionChatLimitCount;


#pragma endregion

#pragma region FixClient Data
	DWORD _FixClampOffset_1;
	DWORD _FixClampOffset_2;
#pragma endregion

#pragma region GM Console Key
	DWORD _ChangeGMConsoleKeyOffet;
	byte _GmConsoleKey;
#pragma endregion

#pragma region  LoadingResolution
	DWORD _LoadingResolutionOffset_1;
	DWORD _LoadingResolutionOffset_2;
	DWORD _LoadingResolutionOffset_3;
	DWORD _LoadingResolutionOffset_4;
#pragma endregion

#pragma region UnderBar COS
	DWORD _COSNopAdress;
	DWORD _COSActionReSize;
	byte _ActionReSize;
	DWORD _COSFix1;
	DWORD _COSFix2;
	byte _COSFix;
#pragma endregion

private:

};