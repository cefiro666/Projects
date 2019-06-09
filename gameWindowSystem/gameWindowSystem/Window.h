#pragma once
#include "Widget.h"

class Window
{
public:
	virtual void setSize(const sf::Vector2f) = 0;
	virtual sf::Vector2f getSize() = 0;
	virtual void setPosition(const sf::Vector2f) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual std::shared_ptr <std::vector 
		<std::shared_ptr <Widget> > > getWidgetsStack() = 0;
};