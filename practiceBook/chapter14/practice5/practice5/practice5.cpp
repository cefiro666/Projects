#include <iostream>

template <class T>
T amax(T* arr, int size)
{
	T max = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int main()
{
	int arrIn[] = {5, 4, 9, 12, 7};
	float arrFl[] = { 5.8F, 4.9F, 9.89F, 12.45F, 7.0F };
	char arrCh[] = { 53, 42, 94, 121, 73 };

	std::cout << "Max - " << amax(arrIn, 5) << std::endl;
	std::cout << "Max - " << amax(arrFl, 5) << std::endl;
	std::cout << "Max - " << amax(arrCh, 5) << std::endl;
}