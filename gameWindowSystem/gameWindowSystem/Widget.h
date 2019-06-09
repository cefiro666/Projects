#pragma once
#include <SFML/Graphics.hpp>

class Widget
{
public:
	Widget();
	void setSize(const sf::Vector2f);
	sf::Vector2f getSize();
	void setPosition(const sf::Vector2f);
	sf::Vector2f getPosition();
	void setOutlineThickness(float);
	void setFillColor(int, int, int);
	void setOutlineColor(int, int, int);
	void rotate(float);
	bool getGlobalBounds(const sf::Vector2i);
	std::shared_ptr<sf::RectangleShape> getRectangle();

private:
	std::shared_ptr<sf::RectangleShape> rectangle;
};