#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> vec2(vec);
	int first1, last1, first2;
	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;
	std::vector<int>::iterator it3;

	it1 = vec.begin();
	while (it1 != vec.end())
	{
		std::cout << *it1++ << std::endl;
	}

	std::cout << "Insert first1... ";
	std::cin >> first1;
	std::cout << "Insert last1... ";
	std::cin >> last1;
	std::cout << "Insert first2... ";
	std::cin >> first2;

	it1 = vec2.begin() + first1;
	it2 = vec2.begin() + last1;
	it3 = vec.begin() + first2;

	std::copy(it1, it2, std::inserter(vec, it3));

	it1 = vec.begin();
	while (it1 != vec.end())
	{
		std::cout << *it1++ << std::endl;
	}
}