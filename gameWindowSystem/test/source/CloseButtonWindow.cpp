#include "CloseButtonWindow.h"


CloseButtonWindow::CloseButtonWindow()
{
	widget = std::make_shared <std::vector <std::shared_ptr 
		<sf::RectangleShape> > >();

	auto areaCloseButton = std::make_shared <sf::RectangleShape>();
	auto stripOneCloseButton = std::make_shared <sf::RectangleShape>();
	auto stripTwoCloseButton = std::make_shared <sf::RectangleShape>();

	areaCloseButton->setSize(sf::Vector2f(20, 20));
	stripOneCloseButton->setSize(sf::Vector2f(1, 18));
	stripTwoCloseButton->setSize(sf::Vector2f(1, 18));

	stripOneCloseButton->rotate(45);
	stripTwoCloseButton->rotate(-45);

	areaCloseButton->setFillColor(sf::Color(50, 50, 50));
	stripOneCloseButton->setFillColor(sf::Color(255, 255, 255));
	stripTwoCloseButton->setFillColor(sf::Color(255, 255, 255));

	widget->push_back(areaCloseButton);
	widget->push_back(stripOneCloseButton);
	widget->push_back(stripTwoCloseButton);
}

void CloseButtonWindow::setPosition(const sf::Vector2f position)
{
	widget->at(0)->setPosition(position);
	widget->at(1)->setPosition(position.x + 16, position.y + 3);
	widget->at(2)->setPosition(position.x + 4, position.y + 4);
}

sf::Vector2f CloseButtonWindow::getPosition()
{
	return widget->at(0)->getPosition();
}

bool CloseButtonWindow::getGlobalBounds(const sf::Vector2i position)
{
	return widget->at(0)->getGlobalBounds().contains(sf::Vector2f(position));
}

std::shared_ptr <std::vector <std::shared_ptr
	<sf::RectangleShape> > > CloseButtonWindow::getWidget()
{
	return widget;
}

void CloseButtonWindow::setColor(int, int, int) {}
void CloseButtonWindow::setSize(const sf::Vector2f) {}

sf::Vector2f CloseButtonWindow::getSize()
{
	return widget->at(0)->getSize();
}