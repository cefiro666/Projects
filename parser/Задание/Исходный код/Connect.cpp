#include "pch.h"
#include "Connect.h"

Connect::Connect(LPCSTR URL)
{
	// инициализация WinInet
	HINTERNET hInternet = InternetOpenA("WinInet", INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);
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

void Connect::UTF8ToANSI()
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

	string r(pszAnsi);
	delete[] pszAnsi;
	data = r;
}

string Connect::getData()
{
	return data;
}