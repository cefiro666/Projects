#include <iostream>

const int MAX = 10;

template <class T>
class Turn
{
public:
	Turn() : m_tail(-1), m_head(-1) {}

	void push(T value)
	{
		arr[++m_tail] = value;
		if (m_tail >= MAX - 1)
		{
			m_tail--;
		}
	}

	T pop()
	{
		T temp = arr[++m_head];

		if (m_head >= MAX - 1)
		{
			m_head--;
		}

		return temp;
	}

private:
	T arr[MAX];

	int m_head;
	int m_tail;
};

int main()
{
	Turn<int> turn1;
	Turn<float> turn2;

	turn1.push(5);
	turn1.push(8);
	turn1.push(34);
	turn1.push(2);
	turn1.push(5);
	turn1.push(8);
	turn1.push(34);
	turn1.push(2);
	turn1.push(5);
	turn1.push(8);
	turn1.push(34);
	turn1.push(2);
	std::cout << turn1.pop() << std::endl;
	std::cout << turn1.pop() << std::endl;
	std::cout << turn1.pop() << std::endl;
	std::cout << turn1.pop() << std::endl;
	turn1.push(89);
	turn1.push(789);
	std::cout << turn1.pop() << std::endl;
	std::cout << turn1.pop() << std::endl;

	turn2.push(5.45F);
	turn2.push(8.32F);
	turn2.push(3.4F);
	turn2.push(2.90F);
	std::cout << turn2.pop() << std::endl;
	std::cout << turn2.pop() << std::endl;
	std::cout << turn2.pop() << std::endl;
	std::cout << turn2.pop() << std::endl;
	turn2.push(8.9F);
	turn2.push(78.9F);
	std::cout << turn2.pop() << std::endl;
	std::cout << turn2.pop() << std::endl;
}