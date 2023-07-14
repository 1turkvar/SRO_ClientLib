#include "OldLoginScreen.h"
#include "MemoryHack.h"
#include "PSCharacterSelect.h"

MemoryHack* _MemOldLoginScreen = new MemoryHack();

int sro_client = 0x400000;


OldLoginScreen::OldLoginScreen(bool SysOpen)
{
	if (SysOpen == true)
	{
		PSCharacterSelect();
		//idols start
		_MemOldLoginScreen->Write(sro_client + 0x0098ADC6, 0xA0);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DF0, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DF1, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DF2, 0xA0);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DF4, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DF5, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DF6, 0xA0);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DF8, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DF9, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DFA, 0xBE);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DFC, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DFD, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DFE, 0x50);
		_MemOldLoginScreen->Write(sro_client + 0x009D7DFF, 0x43);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E00, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E01, 0x40);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E02, 0xBE);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E28, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E29, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E2A, 0x4F);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E2B, 0x43);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E7E, 0xBD);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E84, 0xF0);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E85, 0x85);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E86, 0xF7);
		_MemOldLoginScreen->Write(sro_client + 0x009D7E87, 0x40);
		//idols end
		//idols animations start
		_MemOldLoginScreen->Write(sro_client + 0x009D7CFC, 0xE3);
		_MemOldLoginScreen->Write(sro_client + 0x009D7CFD, 0x68);
		_MemOldLoginScreen->Write(sro_client + 0x009D7CFE, 0x4E);
		_MemOldLoginScreen->Write(sro_client + 0x009D7CFF, 0x43);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D00, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D01, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D02, 0xA0);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D03, 0x41);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D05, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D06, 0xB9);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D08, 0xE3);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D09, 0x68);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D0A, 0x4E);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D0B, 0x43);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D0C, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D0D, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D0E, 0xA0);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D0F, 0x41);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D10, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D11, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7D12, 0xB9);
		//idols anim end
		//CharSelect Distance
		_MemOldLoginScreen->Write(0x00D8AD3E, 0x70417C87);
		//CharSelect Distance end
		_MemOldLoginScreen->Write(sro_client + 0x009D7CA6, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D7CA7, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D601E, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x009D601F, 0x00);
		_MemOldLoginScreen->Write(sro_client + 0x0045F4FD, 0xBC);
		_MemOldLoginScreen->Write(sro_client + 0x0045F4FE, 0x5F);

	}

}
