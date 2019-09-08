#include <iostream>

template <class T>
void swaps(T &val1, T &val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

int main()
{
    int valIn1 = 2; 
	int valIn2 = 6;

	float valFl1 = 2.7F;
	float valFl2 = 6.4F;

	char valCh1 = '2';
	char valCh2 = '6';

	swaps(valIn1, valIn2);
	swaps(valFl1, valFl2);
	swaps(valCh1, valCh2);

	std::cout << valIn1 << "	" << valIn2 << std::endl;
	std::cout << valFl1 << "	" << valFl2 << std::endl;
	std::cout << valCh1 << "	" << valCh2 << std::endl;
}