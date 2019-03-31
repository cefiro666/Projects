#include "pch.h"
#include "Connection.h"

Connection::Connection(LPCSTR URL)
{
	// ������������� WinInet
	HINTERNET hInternet = InternetOpenA("WinInet", INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);
	if (hInternet != NULL)
	{
		// ����������� ������� �� ���������� URL
		HINTERNET hOpenUrlA = InternetOpenUrlA(hInternet, URL, 0, 0, 0, 0);
		// ���������� �������� � ��������� ����������
		if (hOpenUrlA != NULL)
		{
			do {
				// ������ ������ � �����
				hReadFile = InternetReadFile(hOpenUrlA, buffer, sizeof(buffer) - 1, &bytesRead);
				buffer[bytesRead] = 0;

				// ���������� ������ �� ������ � ������
				for (unsigned int i = 0; i < bytesRead; i++)
				{
					data.push_back(buffer[i]);
				}

			} while (!(hReadFile == FALSE || bytesRead == 0));
		}
		else {
			cout << "�� ������� ������������ � ������� �� ���������� ������!" << endl;
		}
		InternetCloseHandle(hOpenUrlA);
	}
	InternetCloseHandle(hInternet);
}

void Connection::UTF8ToANSI()
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

string Connection::getData()
{
	return data;
}