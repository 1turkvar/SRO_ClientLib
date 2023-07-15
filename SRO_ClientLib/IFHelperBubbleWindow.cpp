#include "IFHelperBubbleWindow.h"
#include "wstring05.h"

void CIFHelperBubbleWindow::WriteLine(std::wstring& text, int a2, UINT ForegroundColor, int a4, BYTE FontIndex)
{
    wstring05 noobstring(text.c_str());
    reinterpret_cast<void(__thiscall*)(CIFHelperBubbleWindow*, std::wstring*, int, UINT, int, BYTE)>(0x00776D20)(this, reinterpret_cast<std::wstring*>(&noobstring), a2, ForegroundColor, a4, FontIndex);
}

void CIFHelperBubbleWindow::WriteLine_Price(CIFHelperBubbleWindow& text, int a2, UINT ForegroundColor, int a4, BYTE FontIndex)
{
    CIFHelperBubbleWindow real_text = reinterpret_cast<CIFHelperBubbleWindow&>(text);

    int32_t price = 0;
    _asm mov price, esi;

    std::wstring comma_number = std::to_wstring(price);
    std::wstring price_str = std::to_wstring(price);
    std::wstring full_string = real_text.mys;

    for (int i = comma_number.size() - 3; i > 0; i -= 3)
    {
        comma_number.insert(comma_number.begin() + i, ',');
    }

    size_t start_pos = full_string.find(price_str);
    if (start_pos != std::string::npos)
    {
        full_string.replace(start_pos, price_str.length(), comma_number + L" ");
    }

    real_text.mys = full_string;
    reinterpret_cast<void(__thiscall*)(CIFHelperBubbleWindow*, std::wstring*, int, UINT, int, BYTE)>(0x00776D20)(this, reinterpret_cast<std::wstring*>(&real_text), a2, ForegroundColor, a4, FontIndex);
}
