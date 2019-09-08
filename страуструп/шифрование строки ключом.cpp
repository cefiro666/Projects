#include <iostream>
#include <string>

void encrypt(std::string& str, const std::string& key)
{
	int indexKey = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (indexKey >= key.size()) indexKey = 0;
		str.at(i) = str.at(i) ^ key.at(indexKey);
		indexKey++;
	}
}

int main(int argc, char* argv[])
{
	system("chcp 1251");

	const std::string key = argv[1];
	std::string str;
	std::cout << "Введите строку для шифрования... \n";
	std::getline(std::cin, str);

	encrypt(str, key);

	std::cout << "Зашифрованная строка: \n" << str << std::endl;

	encrypt(str, key);

	std::cout << "\nРасшифрованная строка: \n" << str << std::endl;
}