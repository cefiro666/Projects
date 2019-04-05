#include "pch.h"
#include <iostream>

using namespace std;

const int MAX = 80;
void reversit(char string[MAX]);

int main()
{
	char string[MAX];
	cin.getline(string, MAX, '\n');
	reversit(string);
	cin.get();
}

void reversit(char string[MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		char temp = string[i];
		string[i] = string[MAX - i];
		string[MAX - i] = temp;
		if (string[i] == '\0') break;
	}

	for (int i = MAX; i > 0; i--)
	{
		cout << string[i];
	}
}