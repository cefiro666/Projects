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
	}

	for (int i =0; i < MAX; i++)
	{
		if (string[i] != NULL) cout << string[i];
	}
}