#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5;

int main()
{
	float arr[MAX];

	cout << "Insert float array:\n";
	for (int i = 0; i < MAX; ++i)
	{
		cout << "item " << i << "... ";
		cin >> arr[i];
	}

	sort(arr, arr + MAX);

	cout << "\nSort array:\n";
	for (int i = 0; i < MAX; ++i)
	{
		cout << arr[i] << endl;
	}
}