#include <iostream>

template <class T> 
T summ(T* arr, int size)
{
	T summ = 0;
	for (int i = 0; i < size; i++)
	{
		summ += arr[i];
	}

	return summ / size;
}

int main()
{
	int arr1[] = { 5, 67, 9 };
	float arr2[] = { 5.6F, 4.56F, 9.3F };
	std::cout << summ(arr1, 3) << std::endl;
	std::cout << summ(arr2, 3);
}