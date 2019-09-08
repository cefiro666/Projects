#pragma once
#include "Window.h"

class WindowSFML : public Window
{
public:
	WindowSFML();

	void setSize(const sf::Vector2f) override;
	sf::Vector2f getSize() override;
	void setPosition(const sf::Vector2f) override;
	sf::Vector2f getPosition() override;

	std::shared_ptr <std::vector<std::shared_ptr< Widget> > >
		getWidgetsStack() override;

private:
	std::shared_ptr <std::vector <std::shared_ptr 
		<Widget> > > widgetsStack;
};