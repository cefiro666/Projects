#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Window Title");
	CircleShape shape;
	shape.setRadius(50);
	shape.setFillColor(Color::Red);
	shape.setPosition(100, 400);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
}
