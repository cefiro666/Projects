#include <iostream>
#include <vector>

template<class T> void f(std::vector<std::vector <T> >* vec)
{
	for (size_t j = 0; j < (*vec).size() / 2; j++)
	{
		std::vector <T> temp = (*vec)[j];
		(*vec)[j] = (*vec)[(*vec).size() - j - 1];
		(*vec)[(*vec).size() - j - 1] = temp;
	}

	for (size_t i = 0; i < (*vec).size(); i++)
	{
		for (size_t j = 0; j < (*vec)[i].size() / 2; j++)
		{
			T temp = (*vec)[i][j];
			(*vec)[i][j] = (*vec)[i][(*vec)[i].size() - j - 1];
			(*vec)[i][(*vec)[i].size() - j - 1] = temp;
		}
	}
}

int main(int argc, char* argv[])
{
	std::vector<std::vector <int> > vec(3, std::vector<int> (5));

	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			vec[i][j] = 10* (i+j);
		}
	}

	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			std::cout << vec[i][j] << '\t';
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	f(&vec);

	std::cout << std::endl;

	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			std::cout << vec[i][j] << '\t';
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}