#include <iostream>
#include <string>

long fact(int value)
{
	int sum = 1;

	for (int i = 1; i <= value; i++)
	{
		sum *= i;
	}

	return sum;
}

int main(int argc, char* argv[])
{
	std::cout << fact(12);
}