#pragma once
#include "stdafx.h"


class CIFHelperBubbleWindow
{
public:
	void WriteLine(std::wstring& text, int a2, UINT ForegroundColor, int a4, BYTE FontIndex);
	void CIFHelperBubbleWindow::WriteLine_Price(CIFHelperBubbleWindow& text, int a2, UINT ForegroundColor, int a4, BYTE FontIndex);

	int x;
	std::wstring mys;
};