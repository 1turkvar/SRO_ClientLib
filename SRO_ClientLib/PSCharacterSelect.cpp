// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "stdafx.h"
#include "PSCharacterSelect.h"
#include "static_constructor.h"
#include "Character3D.h"
#include "Keyframe.h"
#include "address_helper.h"


extern HMODULE sro_clientAdress;

#define CHARSEL_CREATE 744
#define CHARSEL_INTRO 743
#define CHARSEL_CHARPOS_1 747
#define CHARSEL_CHARPOS_2 748


#define CHARSEL_KEYFRAME_START CLIENT_OFFSET(0xAC2D88) 
#define CHARSEL_KEYFRAME_END CLIENT_OFFSET(0xAC2DA8) 


#define CHARSEL_KEYFRAME_CREATE_1 CLIENT_OFFSET(0xAC2DC8)
#define CHARSEL_KEYFRAME_CREATE_2 CLIENT_OFFSET(0xAC2DE8)
#define CHARSEL_KEYFRAME_CREATE_3 CLIENT_OFFSET(0xAC2E08)
#define CHARSEL_KEYFRAME_CREATE_4 CLIENT_OFFSET(0xAC2E28)

#define CHARSEL_CHARACTER_POSITION_1 CLIENT_OFFSET(0xAC2E48)
#define CHARSEL_CHARACTER_POSITION_2 CLIENT_OFFSET(0xAC2E58)

#define CHARSEL_RAW_LIZARD_Z CLIENT_OFFSET(0x9D7DF8) 

#define CHARSEL_RAW_CHINESE_Z CLIENT_OFFSET(0x9D7DFC) 
#define CHARSEL_RAW_CHINESE_X CLIENT_OFFSET(0x9D7E00) 

#define CHARSEL_RAW_EUROPE_Z  CLIENT_OFFSET(0x9D7E28) 
#define CHARSEL_RAW_EUROPE_X  CLIENT_OFFSET(0x9D7E7C) 

#define CHARSEL_RAW_CRATE_Z   CLIENT_OFFSET(0x9D7E80)
#define CHARSEL_RAW_CRATE_Y   CLIENT_OFFSET(0x9D7E84)
#define CHARSEL_RAW_CRATE_X   CLIENT_OFFSET(0x9D7EA0) 

#define CHARSEL_CHARACTER_POSITION_YOFFSET CLIENT_OFFSET(0x9D7C98)

void static_const_create(void);
void static_const_intro(void);

void static_const_char_1(void);
void static_const_char_2(void);

void PSCharacterSelect(void)
{
	// We override the constructor list
	client_override_constructor(CHARSEL_INTRO, &static_const_intro);
	client_override_constructor(CHARSEL_CREATE, &static_const_create);

	client_override_constructor(CHARSEL_CHARPOS_1, &static_const_char_1);
	client_override_constructor(CHARSEL_CHARPOS_2, &static_const_char_2);


	DWORD dwProtect = 0;
	// Unprotect first
	if (!VirtualProtect(
		(LPVOID)CHARSEL_CHARACTER_POSITION_YOFFSET,
		sizeof(double),
		PAGE_EXECUTE_READWRITE,
		&dwProtect)) {

		perror("Failed to unprotect memory\n");
		printf("Failed to unprotect memory\n");
		return;
	}

	*((double*)(CHARSEL_CHARACTER_POSITION_YOFFSET)) = 0;

	// aannnd protect
	VirtualProtect((LPVOID)CHARSEL_CHARACTER_POSITION_YOFFSET, sizeof(double), dwProtect, NULL);

}


void static_const_intro(void)
{
	Keyframe* intro_start = (Keyframe*)CHARSEL_KEYFRAME_START;

	intro_start->position.X = 486.626;
	intro_start->position.Y = 10.390;
	intro_start->position.Z = 224.418;

	intro_start->rotation.X = 0.099;
	intro_start->rotation.Y = 0.753;
	intro_start->rotation.Z = 0.000;

	intro_start->distance = 80.000;
	intro_start->time = 0.000; // time is preset and ignored



	Keyframe* intro_end = (Keyframe*)CHARSEL_KEYFRAME_END;

	//F8 Giriþ
	//intro_end->position.X = 486.626;
	//intro_end->position.Y = 10.390;
	//intro_end->position.Z = 241.010;

	intro_end->position.X = 502.171;
	intro_end->position.Y = 8.125;
	intro_end->position.Z = 241.010;

	intro_end->rotation.X = 0.099;
	intro_end->rotation.Y = 0.753;
	intro_end->rotation.Z = 0.000;

	intro_end->distance = 80.000;
	intro_end->time = 5.000; // time is preset and ignored

}

void static_const_create(void) {
	Keyframe* create_1 = (Keyframe*)CHARSEL_KEYFRAME_CREATE_1;

	create_1->position.X = 502.171;
	create_1->position.Y = 8.125;
	create_1->position.Z = 241.010;

	create_1->rotation.X = 0.099;
	create_1->rotation.Y = 0.753;
	create_1->rotation.Z = 0.000;

	create_1->distance = 80.000;
	create_1->time = 0.000; // time is preset and ignored


	Keyframe* create_2 = (Keyframe*)CHARSEL_KEYFRAME_CREATE_2;

	create_2->position.X = 504.531;
	create_2->position.Y = 8.125;
	create_2->position.Z = 235.514;

	create_2->rotation.X = 0.099;
	create_2->rotation.Y = 1.165;
	create_2->rotation.Z = 0.000;

	create_2->distance = 80.000;
	create_2->time = 5.000; // time is preset and ignored	Time = 6'dý 


	Keyframe* create_3 = (Keyframe*)CHARSEL_KEYFRAME_CREATE_3;

	create_3->position.X = 478.134;
	create_3->position.Y = 10.767;
	create_3->position.Z = 231.172;

	create_3->rotation.X = 0.099;
	create_3->rotation.Y = 1.333;
	create_3->rotation.Z = 0.000;

	create_3->distance = 80.000;
	create_3->time = 10.000; // time is preset and ignored


	Keyframe* create_4 = (Keyframe*)CHARSEL_KEYFRAME_CREATE_4;

	create_4->position.X = 376.720;
	create_4->position.Y = 7.733;
	create_4->position.Z = 204.310;

	create_4->rotation.X = 0.800;
	create_4->rotation.Y = 0.809;
	create_4->rotation.Z = 0.000;

	create_4->distance = 6.700;
	create_4->time = 15.000; // time is preset and ignored
}

#pragma region Karakterler
void static_const_char_1(void) {
	Character3D* character = (Character3D*)CHARSEL_CHARACTER_POSITION_1;

	// Blackroque 80
	character->location.X = 460.835;
	character->location.Y = 0.626;
	character->location.Z = 233.131;

	character->rotation = -0.955;
}

void static_const_char_2(void) {
	Character3D* character = (Character3D*)CHARSEL_CHARACTER_POSITION_2;

	// Blackroque 80
	character->location.X = 490.574;
	character->location.Y = 0.986;
	character->location.Z = 194.903;

	character->rotation = -0.828;
}
#pragma endregion