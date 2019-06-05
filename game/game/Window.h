#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window(int, int, int, int, int, sf::RenderWindow*);
	void draw();
	bool onPanel(sf::Vector2f);
	bool onClose(sf::Vector2f);
	void move(sf::Vector2f);
	
private:
	sf::RenderWindow* window;
	sf::RectangleShape windowArea;
	sf::RectangleShape windowPanel;
	sf::RectangleShape windowClose;
	sf::RectangleShape windowCloseStrip1;
	sf::RectangleShape windowCloseStrip2;
	sf::Text numberText;
};