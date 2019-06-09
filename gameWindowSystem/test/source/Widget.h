#pragma once
#include <SFML/Graphics.hpp>

class Widget
{
public:
	virtual void setSize(const sf::Vector2f) = 0;
	virtual sf::Vector2f getSize() = 0;
	virtual void setPosition(const sf::Vector2f) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setColor(int, int, int) = 0;
	virtual bool getGlobalBounds(const sf::Vector2i) = 0;

	virtual std::shared_ptr <std::vector <std::shared_ptr
		<sf::RectangleShape> > > getWidget() = 0;
};