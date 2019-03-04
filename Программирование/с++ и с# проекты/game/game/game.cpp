#include "pch.h"
#include "Ball.h"
#include "Player.h"
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;


int main()
{
	Player left(15, 150, 50, 200, Color::Green);
	Player right(15, 150, 935, 200, Color::Blue);
	Ball ball(10, 500, 300, Color::Red);

	ContextSettings settings;
	settings.antialiasingLevel = 4;
	RenderWindow window(VideoMode(1000, 600), "PONG", Style::Default, settings);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			left.up(10);
		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			left.down(10);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			right.up(10);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			right.down(10);
		}

		window.clear();
		window.draw(left.rectangle);
		window.draw(right.rectangle);
		window.draw(ball.shape);
		window.display();
	}
}
