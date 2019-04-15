#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int compstr(const char*, const char*);
	const char* str1 = "Baaaaaaa";
	const char* str2 = "Baaaaaaa";
	int var = compstr(str1, str2);
	cout << var;
}

int compstr(const char* str1, const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 > len2)
	{
		for (int i = 0; i < len1; i++)
		{
			if (*(str1 + i) > *(str2 + i)) return -1;
			if (*(str1 + i) < *(str2 + i)) return 1;
		}
		return 0;
	} else {
		for (int i = 0; i < len2; i++)
		{
			if (*(str1 + i) > *(str2 + i)) return -1;
			if (*(str1 + i) < *(str2 + i)) return 1;
		}
		return 0;
	}
}