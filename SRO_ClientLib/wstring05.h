#include <Windows.h>
#include <iostream>

class wstring05 {
public:
	wstring05(const wchar_t* cstr)
	{
		allocator = nullptr;
		reserved_size = size = wcslen(cstr);
		if (size < 8)
			memcpy(buffer, cstr, (size + 1) * sizeof(wchar_t));
		else
			p_buffer = cstr;
	}

	const wchar_t* cchar()
	{
		if (reserved_size > sizeof(buffer))
		{
			return p_buffer;
		}
		else
		{
			return buffer;
		}
	}

private:

	void* allocator;
	union {
		wchar_t buffer[8];
		const wchar_t* p_buffer;
	};

	int size;
	int reserved_size;
};
