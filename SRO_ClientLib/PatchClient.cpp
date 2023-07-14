#include "PatchClient.h"
#include "MemoryHack.h"
#include "DataBank.h"

MemoryHack* _MemPatchClient = new MemoryHack();
DataBank* _DataPatchClient = new DataBank();

PatchClient::PatchClient(bool SysOpen)
{
	if (SysOpen == true)
	{
#pragma region PatchClient
		//Level Cap
		_MemPatchClient->Write(_DataPatchClient->_LevelCapOffset, _DataPatchClient->_LevelCap);
		//MaxDG
		_MemPatchClient->Write(_DataPatchClient->_MaxDGOffset, _DataPatchClient->_MaxDGCount);
		//Party Matching Cap
		_MemPatchClient->Write(_DataPatchClient->_PartyMatchingOffset_1, _DataPatchClient->_PartyCap);
		_MemPatchClient->Write(_DataPatchClient->_PartyMatchingOffset_2, _DataPatchClient->_PartyCap);
		_MemPatchClient->Write(_DataPatchClient->_PartyMatchingOffset_3, _DataPatchClient->_PartyCap);
		_MemPatchClient->Write(_DataPatchClient->_PartyMatchingOffset_4, _DataPatchClient->_PartyCap);
		_MemPatchClient->Write(_DataPatchClient->_PartyMatchingOffset_5, _DataPatchClient->_PartyCap);
		_MemPatchClient->Write(_DataPatchClient->_PartyMatchingOffset_6, _DataPatchClient->_PartyCap);
		_MemPatchClient->Write(_DataPatchClient->_PartyMatchingOffset_7, _DataPatchClient->_PartyCap);
		_MemPatchClient->Write(_DataPatchClient->_PartyMatchingOffset_8, _DataPatchClient->_PartyCap);
		//Max Skill
		_MemPatchClient->Write(_DataPatchClient->_SkillCapOffset, _DataPatchClient->_SkillCap);
		//Max Quest
		_MemPatchClient->Write(_DataPatchClient->_QuestCapOffset, _DataPatchClient->_QuestCap);
		//Max Character
		_MemPatchClient->Write(_DataPatchClient->_MaxCharacterOffet, _DataPatchClient->_MaxCharacterCout);
		//Mastery Max Limit
		_MemPatchClient->Write(_DataPatchClient->_MaxMasteryLimitOffset_CH_1, _DataPatchClient->_MaxMasteryCHCount_1);
		_MemPatchClient->Write(_DataPatchClient->_MaxMasteryLimitOffset_CH_2, _DataPatchClient->_MaxMasteryCHCount_2);
		_MemPatchClient->Write(_DataPatchClient->_MaxMasteryLimitOffset_CH_1_1, _DataPatchClient->_MaxMasteryCHCount_1);
		_MemPatchClient->Write(_DataPatchClient->_MaxMasteryLimitOffset_CH_1_2, _DataPatchClient->_MaxMasteryCHCount_2);
		_MemPatchClient->Write(_DataPatchClient->_MaxLevepUpMastery, _DataPatchClient->_MaxLevepUpCap);
		_MemPatchClient->Write(_DataPatchClient->_MaxMasteryLimitOffset_EU_1, _DataPatchClient->_MaxMasteryEUCap);
		_MemPatchClient->Write(_DataPatchClient->_MaxMasteryLimitOffset_EU_2, _DataPatchClient->_MaxMasteryEUCap);
		_MemPatchClient->Write(_DataPatchClient->_MaxMasteryLimitOffset_EU_3, _DataPatchClient->_MaxMasteryEUCap);
		_MemPatchClient->Write(_DataPatchClient->_MaxMasteryLimitOffset_EU_4, _DataPatchClient->_MaxMasteryEUCap);
		//Guild-Union Chat Limit
		_MemPatchClient->Write(_DataPatchClient->_UnionChatLimitOffset, _DataPatchClient->_UnionChatLimitCount);
#pragma endregion

#pragma region FixClient Data
		_MemPatchClient->Write(_DataPatchClient->_FixClampOffset_1, 0x80);
		_MemPatchClient->Write(_DataPatchClient->_FixClampOffset_2, 0x7C);
#pragma endregion

#pragma region GM Console Key
		_MemPatchClient->Write(_DataPatchClient->_ChangeGMConsoleKeyOffet, _DataPatchClient->_GmConsoleKey);
#pragma endregion

#pragma region  LoadingResolution
		_MemPatchClient->Write(_DataPatchClient->_LoadingResolutionOffset_1, 0x04); //320 = 800 , 400 = 1024
		_MemPatchClient->Write(_DataPatchClient->_LoadingResolutionOffset_2, 0x00);
		_MemPatchClient->Write(_DataPatchClient->_LoadingResolutionOffset_3, 0x03); //258 = 600	, 300 = 768
		_MemPatchClient->Write(_DataPatchClient->_LoadingResolutionOffset_4, 0x00);
#pragma endregion

#pragma region UnderBar COS
		_MemPatchClient->Write(_DataPatchClient->_COSActionReSize, _DataPatchClient->_ActionReSize);
		_MemPatchClient->Write(_DataPatchClient->_COSFix1, _DataPatchClient->_COSFix);
		_MemPatchClient->Write(_DataPatchClient->_COSFix2, _DataPatchClient->_COSFix);
		_MemPatchClient->SetNop(_DataPatchClient->_COSNopAdress, 16);
#pragma endregion

	}
	else
	{
		printf("Patch Client System Closed");
	}
}
