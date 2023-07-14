#include "PatchWatermark.h"
#include "MemoryHack.h"

PatchWaterMark::PatchWaterMark(bool SysOpen)
{
	bool succeed;
	auto assert_patch = [&succeed]()
	{
		if (!succeed)
			throw std::runtime_error("cannot patch watermark");
	};
	uint8_t posPatch[8] = { 0xC7, 0x44, 0x24, 0x50, 0xFA, 0xFF, 0xFF, 0xFF };
	succeed = MemoryHack::CopyBytes(0x0086BC10, posPatch, sizeof(posPatch));
	assert_patch();

#pragma pack(push, 1)
	struct
	{
		uint8_t opcode;
		uint32_t color;
	} colorPatch;
#pragma pack(pop)
	colorPatch.opcode = 0x68; // push (constant)
	colorPatch.color = 0xFF00D8D8;
	succeed = MemoryHack::CopyBytes(0x0086BC33, &colorPatch, sizeof(colorPatch));
	assert_patch();

	static std::wstring versionFormat;
	if (versionFormat.length() == 0)
	{
		versionFormat.append(L"Ver %d.%03d\n");
		versionFormat.append(L"Epvp");
	}
#pragma pack(push, 1)
	struct
	{
		uint8_t opcode;
		const wchar_t* address;
	} textPatch;
#pragma pack(pop)
	textPatch.opcode = 0x68;
	textPatch.address = versionFormat.c_str();
	succeed = MemoryHack::CopyBytes(0x0086BC6F, &textPatch, sizeof(textPatch));
	assert_patch();

}
