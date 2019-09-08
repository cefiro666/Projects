#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
	int arr[] = { 2,4,6,8,10 };
	std::set<int, std::less<int> > set;
	std::vector<int> vec(11);

	for (int i = 1; i < 12; i+=2)
	{
		set.insert(i);
	}

	std::merge(arr, arr + 5, set.begin(), set.end(), vec.begin());

	std::vector<int>::iterator iter = vec.begin();
	
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::cout << vec.at(i) << std::endl;
	}
}