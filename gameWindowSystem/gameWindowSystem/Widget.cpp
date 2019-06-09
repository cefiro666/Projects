#include "Widget.h"

Widget::Widget()
{
	rectangle = std::make_shared<sf::RectangleShape>();
}

void Widget::setSize(const sf::Vector2f size)
{
	rectangle->setSize(size);
}

sf::Vector2f Widget::getSize()
{
	return rectangle->getSize();
}

void Widget::setPosition(const sf::Vector2f position)
{
	rectangle->setPosition(position);
}

sf::Vector2f Widget::getPosition()
{
	return rectangle->getPosition();
}

void Widget::setFillColor(int r, int g, int b)
{
	rectangle->setFillColor(sf::Color(r, g, b));
}

void Widget::setOutlineThickness(float width)
{
	rectangle->setOutlineThickness(width);
}

void Widget::setOutlineColor(int r, int g, int b)
{
	rectangle->setOutlineColor(sf::Color(r, g, b));
}

void Widget::rotate(float angle)
{
	rectangle->rotate(angle);
}

bool Widget::getGlobalBounds(const sf::Vector2i position)
{
	return rectangle->getGlobalBounds().contains(sf::Vector2f(position));
}

std::shared_ptr<sf::RectangleShape> Widget::getRectangle()
{
	return rectangle;
}