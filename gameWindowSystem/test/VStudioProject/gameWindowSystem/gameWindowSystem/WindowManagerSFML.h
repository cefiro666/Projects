#pragma once
#include "WindowManager.h"

class WindowManagerSFML : public WindowManager
{
public:
	WindowManagerSFML();

	void createWindow(const sf::Vector2f) override;
	bool deleteWindow(const sf::Vector2i) override;
	void moveWindow(const sf::Vector2i, bool) override;
	void upWindow(const sf::Vector2i) override;
	void downWindow(const sf::Vector2i) override;
	int getActiveWindow(const sf::Vector2i) override;
	void formingWindows() override;

	std::shared_ptr <std::vector <std::shared_ptr <Window> > > 
		getWindowsStack() override;

private:
	std::shared_ptr <std::vector <std::shared_ptr 
		<Window> > > windowsStack;

	size_t activeWindow;
};