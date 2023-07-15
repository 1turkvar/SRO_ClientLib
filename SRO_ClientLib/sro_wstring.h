#pragma once
#include <Windows.h>
#include <iostream>
class sro_wstring
{
private:
	int unk0;

	union
	{
		wchar_t* m_wchContentPtr;
		wchar_t m_wchContentBuffer[8];
	};

	int m_iLength;
	int m_iMaxLength;

public:
	sro_wstring()
	{
	}

	sro_wstring(wchar_t* _Ptr)
	{
		assign(_Ptr);
	}

	void assign(wchar_t* _Ptr)
	{
		m_iLength = wcslen(_Ptr);
		m_iMaxLength = wcslen(_Ptr);

		if (m_iMaxLength < 8)
		{
			wcscpy_s(m_wchContentBuffer, _Ptr);
		}
		else
		{
			m_wchContentPtr = _Ptr;
		}
	}

	const wchar_t* c_wstr()
	{
		return m_iMaxLength < 8 ? m_wchContentBuffer : *reinterpret_cast<wchar_t**>(m_wchContentBuffer);
	}
};