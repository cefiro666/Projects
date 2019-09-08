#include <iostream>
#include <string>

std::string binary(int value)
{
	std::string bin;
	int byte;
	while (value)
	{
		byte = value % 2;
		value /= 2;
		bin = std::to_string(byte) + bin;
	}
	return bin;
}

void print(int value, int base = 10)
{
	switch (base)
	{
	case 16:
		std::cout << std::hex << value << std::endl;
		break;
	case 10:
		std::cout << std::dec << value << std::endl;
		break;
	case 2:
		std::cout << binary(value) << std::endl;
		break;
	}
}

int main(int argc, char* argv[])
{
	print(456, 16);
	print(456, 2);
	print(456);
}