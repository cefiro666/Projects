#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector <string> str;
	char ch;

	cout << "Insert string array:\n";
	string temp;

	do {

		cout << "Input word... ";
		cin >> temp;
		str.push_back(temp);
		cout << "Repeat? (y/n)... ";
		cin >> ch;

	} while (ch != 'n');

	sort(str.begin(), str.end());

	cout << "\nSort array:\n";
	
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << endl;
	}
}