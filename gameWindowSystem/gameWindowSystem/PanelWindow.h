#pragma once
#include "Widget.h"

class PanelWindow : public Widget
{
public:
	PanelWindow();

	virtual void setSize(const sf::Vector2f) override;
	virtual sf::Vector2f getSize() override;
	void setPosition(const sf::Vector2f) override;
	sf::Vector2f getPosition() override;
	void setColor(int, int, int) override;
	bool getGlobalBounds(const sf::Vector2i) override;

	std::shared_ptr <std::vector <std::shared_ptr
		<sf::RectangleShape> > > getWidget() override;

private:
	std::shared_ptr <std::vector <std::shared_ptr
		<sf::RectangleShape> > > widget;
};

