#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> lInt;

	lInt.push_back(5);
	lInt.push_back(3);
	lInt.push_back(8);
	lInt.push_back(53);
	lInt.push_back(6);
	lInt.push_back(89);

	vector<int>::iterator it1 = lInt.begin();
	vector<int>::reverse_iterator it2 = lInt.rbegin();

	int temp;
	while (it1 != it2.base())
	{
		temp = *it1;
		*it1 = *it2;
		*it2 = temp;
		++it1;

		if (it1 == it2.base())
		{
			break;
		}

		++it2;
	}

	it1 = lInt.begin();

	while (it1 != lInt.end())
	{
		cout << *it1++ << endl;
	}
}