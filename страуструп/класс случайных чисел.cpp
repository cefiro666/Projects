#include <iostream>
#include <ctime>

class Rand
{
public:
	Rand(int, int);
	int draw();

private:
	int min;
	int max;
};

inline Rand::Rand(int min, int max) : min(min), max(max)
{
	srand(static_cast<unsigned int>(time(0)));
}

inline int Rand::draw()
{
	rand();
	return min + rand() % ((max - min) + 1);
}