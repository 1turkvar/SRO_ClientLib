#include "stdafx.h"
#include "Globals.h"

HMODULE sro_clientAdress = 0;


//////////////////////////////////////* System OK *///////////////////////////////////////////////
void InitThreadWorker()
{
	g_PatchClient = new PatchClient(true); //-> Oyun içi bazý fix ve Cap vs ayarlar
	g_PatchWaterMark = new PatchWaterMark(true); //-> Giriþ Veriyon Renklendirme vs yazý ekleme

	//Old
	g_OldLoginScreen = new OldLoginScreen(true);
	g_OldUnderBar = new OldUnderBar(true);
	g_OldTargetWnd = new OldTargetWnd(true);
	g_OldItemTooltip = new OldItemTooltip(true);
	g_OldAlchemyWnd = new OldAlchemyWnd(true);
	g_OldMainPopWnd = new OldMainPopWnd(true);
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		DisableThreadLibraryCalls(hModule);

		//AllocConsole();
		//freopen("CONOUT$", "w+", stdout);

		//cout << "===========================================\n";
		//cout << "[Ancient Silkroad Online] - SRO_ClientLib.dll loaded\nAuthor: 1TurkVar\nMail:    tulpardestek@gmail.com\n";
		//cout << "===========================================\n";
		//

		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)InitThreadWorker, NULL, 0, NULL);
		sro_clientAdress = GetModuleHandle(NULL);
		std::cout << "Adress :" << sro_clientAdress << std::endl;


	}
	break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;

	}
	return TRUE;
}

__declspec(dllexport) void __cdecl Start(void)
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)InitThreadWorker, NULL, 0, NULL);
}
