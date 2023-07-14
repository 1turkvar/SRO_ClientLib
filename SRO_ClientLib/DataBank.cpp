#include "DataBank.h"

DataBank::DataBank()
{
#pragma region PatchClient Data
	//Max Cap Ayarlarý
	//------------------------------------------------------------//
	this->_CAP = 0x3C;
	this->_LevelCap = _CAP; //0x6E = 110, 0x50 = 80
	this->_PartyCap = _CAP; //0x6E = 110, 0x50 = 80
	this->_SkillCap = _CAP; //0x6E = 110, 0x50 = 80
	this->_QuestCap = _CAP; //0x6E = 110, 0x50 = 80
	this->_MaxDGCount = 0x06;
	this->_MaxCharacterCout = 0x04; //-> 4 adet
	this->_MaxLevepUpCap = _CAP; //0x6E = 110, 0x50 = 80
	this->_MaxMasteryCHCount_1 = 0x00;  //01		//00
	this->_MaxMasteryCHCount_2 = 0xB4;  //4A ->330	//FA ->240
	this->_MaxMasteryEUCap = 0x78;	//A0 = 160, DC = 110
	this->_UnionChatLimitCount = 0x0C; //0C = 12
	//------------------------------------------------------------//

	//Level Cap
	this->_LevelCapOffset = (0x008A99A2 + 2);
	//MaxDG
	this->_MaxDGOffset = (0x009E22E8 + 2);
	//Party Matching Cap
	this->_PartyMatchingOffset_1 = (0x0073940E + 1);
	this->_PartyMatchingOffset_2 = (0x00739453 + 1);
	this->_PartyMatchingOffset_3 = (0x0073AFAE + 1);
	this->_PartyMatchingOffset_4 = (0x0073B013 + 1);
	this->_PartyMatchingOffset_5 = (0x0073B030 + 1);
	this->_PartyMatchingOffset_6 = (0x0073FA4C + 1);
	this->_PartyMatchingOffset_7 = (0x0073FAAF + 1);
	this->_PartyMatchingOffset_8 = (0x0073FACC + 1);
	//Max Skill
	this->_SkillCapOffset = (0x009448B1 + 6);
	//Max Quest
	this->_QuestCapOffset = (0x00955134 + 3);
	//Max Character
	this->_MaxCharacterOffet = (0x0085DE67 + 6);
	//Mastery Max Limit
	this->_MaxMasteryLimitOffset_CH_1 = (0x006A51BC + 2);
	this->_MaxMasteryLimitOffset_CH_2 = (0x006A51BC + 1);
	this->_MaxMasteryLimitOffset_CH_1_1 = (0x006AA4C3 + 2);
	this->_MaxMasteryLimitOffset_CH_1_2 = (0x006AA4C3 + 1);
	this->_MaxLevepUpMastery = (0x0069C7C8 + 1);
	this->_MaxMasteryLimitOffset_EU_1 = (0x006A5197 + 1);
	this->_MaxMasteryLimitOffset_EU_2 = (0x006A51A2 + 1);
	this->_MaxMasteryLimitOffset_EU_3 = (0x006AA498 + 1);
	this->_MaxMasteryLimitOffset_EU_4 = (0x006AA4A3 + 1);
	//Guild-Union Chat Limit
	this->_UnionChatLimitOffset = (0x005AC538 + 1);

#pragma endregion

#pragma region FixClient Data
	this->_FixClampOffset_1 = 0x007A9B18;
	this->_FixClampOffset_2 = 0x007A9B20;
#pragma endregion

#pragma region GM Console Key
	this->_GmConsoleKey = 0x47;
	this->_ChangeGMConsoleKeyOffet = 0x0078B697;
#pragma endregion

#pragma region  LoadingResolution
	this->_LoadingResolutionOffset_1 = 0x0086D40A; //320 = 800
	this->_LoadingResolutionOffset_2 = 0x0086D409;
	this->_LoadingResolutionOffset_3 = 0x0086D412; //258 = 600
	this->_LoadingResolutionOffset_4 = 0x0086D411;
#pragma endregion

#pragma region UnderBar COS
	this->_COSNopAdress = 0x007A265E;
	this->_COSActionReSize = 0x007A2611;
	this->_ActionReSize = 0x1E;
	this->_COSFix1 = 0x007A2676;
	this->_COSFix2 = 0x007A2684;
	this->_COSFix = 0x00;
#pragma endregion
}

DataBank::~DataBank()
{
}
