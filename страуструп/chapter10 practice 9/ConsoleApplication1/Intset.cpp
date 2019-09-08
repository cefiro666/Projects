#include "Intset.h"

using namespace Ints;

Intset::Intset(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		set.emplace(*arr++);
	}
}

void Intset::add(int i)
{
	set.emplace(i);
}

void Intset::del(int i)
{
	set.erase(i);
}

void Intset::print()
{
	for (i = set.begin(); i != set.end(); i++)
	{
		std::cout << *i << '\n';
	}
}

void Intset::inter(Intset& n1)
{
	for (i = n1.set.begin(); i != n1.set.end(); i++)
	{
		if (set.find(*i) != set.end()) set.erase(*i);
		else set.emplace(*i);
	}
}

void Intset::uni(Intset & n1)
{
	for (i = n1.set.begin(); i != n1.set.end(); i++)
	{
		set.emplace(*i);
	}
}