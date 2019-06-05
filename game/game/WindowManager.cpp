#include "WindowManager.h"

WindowManager::WindowManager(sf::RenderWindow* window) : window(window) {}

void WindowManager::drawWindows()
{
	window->clear();

	for (auto window = windowList.begin(); window != windowList.end(); window++)
	{
		window->draw();
	}

	window->display();
}

void WindowManager::createWindow(int width, int hight)
{
	int numberWindow = windowList.size() + 1;
	int positionX = 200 + 50 * windowList.size();
	int positionY = 200 + 50 * windowList.size();

	Window window(width, hight, positionX,
		positionY, numberWindow, this->window);

	windowList.push_back(window);
}

void WindowManager::deleteWindow(int numberWindow, sf::Vector2i mausePosition)
{
	auto window = windowList.begin() + numberWindow;
	if (window->onClose((sf::Vector2f)mausePosition))
	{
		windowList.erase(window);
	}
}

int WindowManager::activeWindow(sf::Vector2i mausePosition)
{
	int numberWindow = 0;

	for (auto window = windowList.begin(); window != windowList.end(); window++)
	{
		if (window->onPanel((sf::Vector2f)mausePosition)) return numberWindow;
		numberWindow++;
	}

	return -1;
}

void WindowManager::moveWindow(int numberWindow, sf::Vector2i mausePosition)
{
	auto window = windowList.begin() + numberWindow;
	window->move((sf::Vector2f)mausePosition);
}