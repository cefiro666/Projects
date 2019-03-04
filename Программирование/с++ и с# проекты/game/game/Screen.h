#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Screen
{
private:
	int width;
	int height;
	int antialiasingLevel;
	int framerateLimit;
	string title;
	RenderWindow window;

public:
	Screen(int width, int height, int antialiasingLevel, int framerateLimit, string title);
	friend int main();
};