#include "Window.h"

Window::Window(int w, int h, int x, int y, int number, sf::RenderWindow* window) : window(window)
{
	windowArea.setSize(sf::Vector2f(w, h));
	windowArea.setPosition(x, y);
	windowArea.setOutlineColor(sf::Color(0,	149	,182));
	windowArea.setOutlineThickness(3);

	windowClose.setSize(sf::Vector2f(27, 27));
	windowClose.setPosition(x + w - 27, y);
	windowClose.setFillColor(sf::Color(50, 50, 50));

	windowCloseStrip1.setSize(sf::Vector2f(2, 25));
	windowCloseStrip1.setPosition(sf::Vector2f(x + w - 6, y + 4));
	windowCloseStrip1.setFillColor(sf::Color(255, 255, 255));
	windowCloseStrip1.rotate(45);

	windowCloseStrip2.setSize(sf::Vector2f(2, 25));
	windowCloseStrip2.setPosition(sf::Vector2f(x + w - 23, y + 5));
	windowCloseStrip2.setFillColor(sf::Color(255, 255, 255));
	windowCloseStrip2.rotate(-45);

	windowPanel.setSize(sf::Vector2f(w, 30));
	windowPanel.setFillColor(sf::Color(0, 149, 182));
	windowPanel.setPosition(sf::Vector2f(x, y));

	numberText.setString(" Window " + std::to_string(number));
	//numberText.setFont();
	numberText.setPosition(x, y);
}

void Window::draw()
{
	window->draw(windowArea);
	window->draw(windowPanel);
	window->draw(windowClose);
	window->draw(windowCloseStrip1);
	window->draw(windowCloseStrip2);
	window->draw(numberText);
}

bool Window::onPanel(sf::Vector2f pos)
{
	return windowPanel.getGlobalBounds().contains(pos);
}

void Window::move(sf::Vector2f pos)
{
	int x = pos.x - windowPanel.getSize().x / 2;
	int y = pos.y - windowPanel.getSize().y / 2;
	windowArea.setPosition(x, y);
	windowClose.setPosition(x + windowArea.getSize().x - 27, y);
	windowCloseStrip1.setPosition(x + windowArea.getSize().x - 6, y + 4);
	windowCloseStrip2.setPosition(x + windowArea.getSize().x - 23, y + 5);
	windowPanel.setPosition(x, y);
}

bool Window::onClose(sf::Vector2f pos)
{
	return windowClose.getGlobalBounds().contains(pos);
}