#include "static_constructor.h"

extern HMODULE sro_clientAdress;

#define STATIC_CONSTRUCTOR_LIST_START 0x98065C
#define STATIC_CONSTRUCTOR_LIST_END   0x981800
#define STATIC_CONSTRUCTOR_LIST_SIZE (STATIC_CONSTRUCTOR_LIST_END - STATIC_CONSTRUCTOR_LIST_START)

int client_override_constructor(int id, void(*function)(void))
{
	DWORD dwProtect = 0;

	if (id < 0) {
		return 0;
	}

	if (id > STATIC_CONSTRUCTOR_LIST_SIZE) {
		return 0;
	}

	static_constructor* list = (static_constructor*)((int)sro_clientAdress + STATIC_CONSTRUCTOR_LIST_START);

	printf("[StaticConst] Have list at %08p\n", list);

	printf("[StaticConst] Unprotecting %d bytes of memory at %08p\n", sizeof(static_constructor*), &list[id]);

	// Unprotect first
	if (!VirtualProtect(
		(LPVOID)(&(list[id])),
		sizeof(static_constructor*),
		PAGE_EXECUTE_READWRITE,
		&dwProtect)) {

		perror("Failed to unprotect memory\n");
		printf("Failed to unprotect memory\n");
		return 0;
	}

	list[id] = function;

	// aannnd protect
	VirtualProtect(
		(LPVOID)(&(list[id])),
		sizeof(static_constructor*), dwProtect, NULL);

	return 1;
}
