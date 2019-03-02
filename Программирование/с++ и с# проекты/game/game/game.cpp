#include "pch.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Lesson 1. kychka-pc.ru");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);
	shape.setPosition(100, 100);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}