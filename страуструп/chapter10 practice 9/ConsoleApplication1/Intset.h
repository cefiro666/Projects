#pragma once

#include <iostream>
#include <set>

namespace Ints
{
	class Intset
	{
	public:
		Intset() {};
		Intset(int* arr, int size);

		void add(int i);
		void del(int i);
		void print();
		void inter(Intset& n1);
		void uni(Intset& n1);

	private:
		std::set<int> set;
		std::set<int>::iterator i;
	};
}
