#include <iostream>
#include <string>

const int MAX = 10;

template <class T>
class Turn
{
public:
	Turn() : m_tail(-1), m_head(-1), count(0) {}

	class Exeption 
	{
	public:
		std::string NameEx;

		Exeption(std::string name) : NameEx(name) {}
	};

	void push(T value)
	{
		if (count == (MAX - 1))
		{
			throw Exeption("Mistake! The queue is full!");
		}

		arr[++m_tail] = value;
		if (m_tail >= MAX - 1)
		{
			m_tail--;
		}

		count++;
	}

	T pop()
	{
		if (count == 0)
		{
			throw Exeption("Mistake! The queue is empty!");
		}
		
		T temp = arr[++m_head];

		if (m_head >= MAX - 1)
		{
			m_head--;
		}

		count--;

		return temp;
	}

private:
	T arr[MAX];

	int count;
	int m_head;
	int m_tail;
};

int main()
{
	Turn<int> turn1;
	char choice;
	int value;
	bool end = false;

	do {
		try
		{
			std::cout << "\nSelect an action:\n"
						 "1. Queue in\n"
						 "2. Remove from the queue\n"
						 "3. Exit\n"
						 "Your choice... ";
			std::cin >> choice;
			switch (choice)
			{
			case '1':
				std::cout << "Enter value... ";
				std::cin >> value;
				turn1.push(value);
				break;
			case '2':
				std::cout << "Next item - " << turn1.pop() << std::endl;
				break;
			case '3':
				end = true;
				break;
			}
		}

		catch (Turn<int>::Exeption ex)
		{
			std::cout << ex.NameEx << std::endl;
		}

	} while (!end);
}