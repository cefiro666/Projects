#pragma once
#include "Window.h"

class WindowManager
{
public:
	virtual void createWindow(const sf::Vector2f) = 0;
	virtual bool deleteWindow(const sf::Vector2i) = 0;
	virtual void moveWindow(const sf::Vector2i, bool) = 0;
	virtual void upWindow(const sf::Vector2i) = 0;
	virtual void downWindow(const sf::Vector2i) = 0;
	virtual int getActiveWindow(const sf::Vector2i) = 0;
	virtual void formingWindows() = 0;
	virtual std::shared_ptr<std::vector<std::shared_ptr<Window> > >
		getWindowsStack() = 0;
};