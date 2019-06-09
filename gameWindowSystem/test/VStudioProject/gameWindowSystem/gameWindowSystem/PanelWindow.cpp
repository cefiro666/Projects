#include "PanelWindow.h"

PanelWindow::PanelWindow()
{
	widget = std::make_shared <std::vector <std::shared_ptr 
		<sf::RectangleShape> > >();

	auto panel = std::make_shared <sf::RectangleShape>();

	widget->push_back(panel);
}

void PanelWindow::setSize(const sf::Vector2f size)
{
	widget->at(0)->setSize(size);
}

sf::Vector2f PanelWindow::getSize()
{
	return widget->at(0)->getSize();
}

void PanelWindow::setPosition(const sf::Vector2f position)
{
	widget->at(0)->setPosition(position);
}

sf::Vector2f PanelWindow::getPosition()
{
	return widget->at(0)->getPosition();
}

void PanelWindow::setColor(int r, int g, int b) 
{
	widget->at(0)->setFillColor(sf::Color(r, g, b));
}

bool PanelWindow::getGlobalBounds(const sf::Vector2i position)
{
	return widget->at(0)->getGlobalBounds().contains(sf::Vector2f(position));
}

std::shared_ptr <std::vector <std::shared_ptr
	<sf::RectangleShape> > > PanelWindow::getWidget()
{
	return widget;
}