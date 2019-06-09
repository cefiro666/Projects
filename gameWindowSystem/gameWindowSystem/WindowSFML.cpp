#include "WindowSFML.h"

WindowSFML::WindowSFML()
{
	widgetsStack = std::make_shared <std::vector <std::shared_ptr <Widget> > >();

	// создаем указатели на виджеты
	auto windowArea = std::make_shared <Widget>();
	auto windowPanel = std::make_shared <Widget>();
	auto windowCloseButton = std::make_shared <Widget>();
	auto windowCloseButtonStripOne = std::make_shared <Widget>();
	auto windowCloseButtonStripTwo = std::make_shared <Widget>();

	//устанавливаем немен€ющиес€ характеристики виджетов окна
	windowCloseButton->setSize(sf::Vector2f(27, 27));
	windowCloseButtonStripOne->rotate(45);
	windowCloseButtonStripTwo->rotate(-45);
	windowCloseButtonStripOne->setSize(sf::Vector2f(2, 25));
	windowCloseButtonStripTwo->setSize(sf::Vector2f(2, 25));

	// добавл€ем виджеты в стек
	widgetsStack->push_back(windowArea);
	widgetsStack->push_back(windowPanel);
	widgetsStack->push_back(windowCloseButton);
	widgetsStack->push_back(windowCloseButtonStripOne);
	widgetsStack->push_back(windowCloseButtonStripTwo);
}

void WindowSFML::setSize(const sf::Vector2f size)
{
	widgetsStack->at(0)->setSize(size);
	widgetsStack->at(1)->setSize(sf::Vector2f(size.x, 30));
}

sf::Vector2f WindowSFML::getSize()
{
	return widgetsStack->at(0)->getSize();
}

void WindowSFML::setPosition(const sf::Vector2f position)
{
	widgetsStack->at(0)->setPosition(position);

	widgetsStack->at(1)->setPosition(position);

	widgetsStack->at(2)->setPosition(sf::Vector2f(position.x + widgetsStack->
		at(0)->getSize().x - widgetsStack->at(2)->getSize().x, position.y));

	widgetsStack->at(3)->setPosition(sf::Vector2f(position.x + widgetsStack->
		at(0)->getSize().x - 5, position.y + 4));

	widgetsStack->at(4)->setPosition(sf::Vector2f(position.x + widgetsStack->
		at(0)->getSize().x - 22, position.y + 5));
}

sf::Vector2f WindowSFML::getPosition()
{
	return widgetsStack->at(0)->getPosition();
}

std::shared_ptr <std::vector <std::shared_ptr <Widget> > > 
	WindowSFML::getWidgetsStack()
{
	return widgetsStack;
}