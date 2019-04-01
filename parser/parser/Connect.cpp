#include "pch.h"
#include "Connect.h"

Connect::Connect(LPCSTR URL)
{
	// инициализация WinInet
	HINTERNET hInternet = InternetOpenA("WinInet", 
		INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);

	if (hInternet != NULL)
	{
		// подключение ресурса по указанному URL
		HINTERNET hOpenUrlA = InternetOpenUrlA(hInternet, URL, 0, 0, 0, 0);
		cout << " -Connection setup... ";
		if (hOpenUrlA != NULL)
		{	
			// считывание страницы html в буфер по 1024 байта
			cout << "            Done" << endl << " -Getting data from a resource... ";
			do {
				// читаем данные в промежуточный буфер
				hReadFile = InternetReadFile(hOpenUrlA, buffer, sizeof(buffer) - 1, &bytesRead);
				buffer[bytesRead] = 0;

				// записываем данные в основной буфер
				for (unsigned int i = 0; i < bytesRead; i++)
				{
					data.push_back(buffer[i]);
				}

			} while (!(hReadFile == FALSE || bytesRead == 0));
			cout << "Done" << endl;
		} else {
			cout << "\n\n Connection failed!\n" << endl;
			exit(0);
		}
		InternetCloseHandle(hOpenUrlA);
	}
	InternetCloseHandle(hInternet);
}

bool Connect::is_valid_utf8()
{
	const char * string = data.c_str();
	if (!string)
		return true;

	const unsigned char * bytes = (const unsigned char *)string;
	unsigned int cp;
	int num;

	while (*bytes != 0x00)
	{
		if ((*bytes & 0x80) == 0x00)
		{
			// U+0000 to U+007F 
			cp = (*bytes & 0x7F);
			num = 1;
		}
		else if ((*bytes & 0xE0) == 0xC0)
		{
			// U+0080 to U+07FF 
			cp = (*bytes & 0x1F);
			num = 2;
		}
		else if ((*bytes & 0xF0) == 0xE0)
		{
			// U+0800 to U+FFFF 
			cp = (*bytes & 0x0F);
			num = 3;
		}
		else if ((*bytes & 0xF8) == 0xF0)
		{
			// U+10000 to U+10FFFF 
			cp = (*bytes & 0x07);
			num = 4;
		}
		else
			return false;

		bytes += 1;
		for (int i = 1; i < num; ++i)
		{
			if ((*bytes & 0xC0) != 0x80)
				return false;
			cp = (cp << 6) | (*bytes & 0x3F);
			bytes += 1;
		}

		if ((cp > 0x10FFFF) ||
			((cp >= 0xD800) && (cp <= 0xDFFF)) ||
			((cp <= 0x007F) && (num != 1)) ||
			((cp >= 0x0080) && (cp <= 0x07FF) && (num != 2)) ||
			((cp >= 0x0800) && (cp <= 0xFFFF) && (num != 3)) ||
			((cp >= 0x10000) && (cp <= 0x1FFFFF) && (num != 4)))
			return false;
	}
	return true;
}

void Connect::utf8toAnsi()
{
	BSTR    bstrWide;
	char*   pszAnsi;
	int     nLength;
	const char *pszCode = data.c_str();

	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);

	MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, bstrWide, nLength);

	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];

	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
	SysFreeString(bstrWide);

	string ansi(pszAnsi);
	delete[] pszAnsi;
	data = ansi;
}

string Connect::getData()
{
	return data;
}