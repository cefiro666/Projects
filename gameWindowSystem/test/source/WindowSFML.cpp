#include "WindowSFML.h"
#include "AreaWindow.h"
#include "CloseButtonWindow.h"
#include "PanelWindow.h"

WindowSFML::WindowSFML()
{
	widgetsStack = std::make_shared <std::vector <std::shared_ptr <Widget> > >();

	std::shared_ptr <Widget> areaWindow(new AreaWindow);
	std::shared_ptr <Widget> panelWindow(new PanelWindow);
	std::shared_ptr <Widget> closeButtonWindow(new CloseButtonWindow);

	widgetsStack->push_back(areaWindow);
	widgetsStack->push_back(panelWindow);
	widgetsStack->push_back(closeButtonWindow);
}

void WindowSFML::setSize(const sf::Vector2f size)
{
	widgetsStack->at(0)->setSize(size);
	widgetsStack->at(1)->setSize(sf::Vector2f(size.x, 23));
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