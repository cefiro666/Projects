#include "pch.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Lesson 1. kychka-pc.ru");
	CircleShape shape(30);
	shape.setFillColor(Color::Green);
	float x = 100;
	float y = 100;
	while (window.isOpen())
	{
		
		shape.setPosition(x, y);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			if (shape.getFillColor() == Color::Red) {
				shape.setFillColor(Color::Green);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			if (shape.getFillColor() == Color::Green) {
				shape.setFillColor(Color::Red);
			}
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (!(shape.getPosition().x >= window.getSize().x-shape.getRadius()*2 )) {
				x += 0.1;
				shape.setPosition(x, y);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (!(shape.getPosition().y <= 0)) {
				y -= 0.1;
				shape.setPosition(x, y);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (!(shape.getPosition().x <= 0)) {
				x -= 0.1;
				shape.setPosition(x, y);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (!(shape.getPosition().y >= window.getSize().y - shape.getRadius() * 2)) {
				y += 0.1;
				shape.setPosition(x, y);
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
}