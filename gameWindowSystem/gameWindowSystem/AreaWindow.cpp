#include "AreaWindow.h"

AreaWindow::AreaWindow()
{
	widget = std::make_shared <std::vector <std::shared_ptr 
		<sf::RectangleShape> > >();

	auto areaWindow = std::make_shared <sf::RectangleShape>();

	areaWindow->setOutlineThickness(3);

	widget->push_back(areaWindow);
}

void AreaWindow::setSize(const sf::Vector2f size)
{
	widget->at(0)->setSize(size);
}

sf::Vector2f AreaWindow::getSize()
{
	return widget->at(0)->getSize();
}

void AreaWindow::setPosition(const sf::Vector2f position)
{
	widget->at(0)->setPosition(position);
}

sf::Vector2f AreaWindow::getPosition()
{
	return widget->at(0)->getPosition();
}

void AreaWindow::setColor(int r, int g, int b)
{
	widget->at(0)->setOutlineColor(sf::Color(r, g, b));
}

bool AreaWindow::getGlobalBounds(const sf::Vector2i position)
{
	return widget->at(0)->getGlobalBounds().contains(sf::Vector2f(position));
}

std::shared_ptr <std::vector <std::shared_ptr
	<sf::RectangleShape> > > AreaWindow::getWidget()
{
	return widget;
}