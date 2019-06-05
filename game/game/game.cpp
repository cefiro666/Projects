#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "WindowManager.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(1400, 900), " WindowSystem", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	
	bool isMove = false;
	bool move = false;
	int number;

	WindowManager manager(&window);

	while (window.isOpen())
	{
		sf::Vector2i mausePosition = sf::Mouse::getPosition(window);
		int numberWindow = manager.activeWindow(mausePosition);
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					if (numberWindow != -1)
					{
						manager.deleteWindow(numberWindow, mausePosition);
						numberWindow = -1;
					}

					isMove = true;
				}
					
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					move = false;
					isMove = false;
				}
			}
				
			if (isMove && numberWindow != -1 || move)
			{
				if (!move)
				{
					number = numberWindow;
					move = true;
					manager.moveWindow(number, mausePosition);

				} else {

					manager.moveWindow(number, mausePosition);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) manager.createWindow(500, 300);

			manager.drawWindows();

		}
	}
}