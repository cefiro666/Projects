#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{	
	vector<string> stlist{"qwe", "wer", "ert", "dfg", "fgf"};
	vector<string>::iterator it1;
	string str;

	cout << "Insert string... ";
	cin >> str;

	it1 = find_if(stlist.begin(), stlist.end(), bind2nd(equal_to<string>(), str));

	if (it1 != stlist.end()) {
		cout << "Find! Index - " << it1 - stlist.begin();
	}
	else {
		cout << "No find!";
	}
}