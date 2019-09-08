#include <iostream>
#include <set>
#include "Intset.h"

int main()
{
	int arr[10];
	Ints::Intset nod;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
		nod.add(i);
	}
	Ints::Intset node(arr, 10);
	node.print();
	nod.print();
	std::cout << '\n';

	nod.inter(node);
	nod.print();
}