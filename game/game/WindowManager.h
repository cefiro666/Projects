#pragma once
#include "Window.h"
#include <vector>

class WindowManager
{
public:
	WindowManager(sf::RenderWindow*);

	void drawWindows();
	void createWindow(int, int);
	void deleteWindow(int, sf::Vector2i);
	int activeWindow(sf::Vector2i);
	void moveWindow(int, sf::Vector2i);

private:
	sf::RenderWindow* window;
	std::vector<Window> windowList;
};

