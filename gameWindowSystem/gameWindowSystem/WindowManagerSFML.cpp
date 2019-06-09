#include "WindowManagerSFML.h"
#include "WindowSFML.h"

WindowManagerSFML::WindowManagerSFML()
{
	windowsStack = std::make_shared <std::vector <std::shared_ptr <Window> > >();
	activeWindow = 0;
}

void WindowManagerSFML::createWindow(const sf::Vector2f size)
{
	// создаем указатель на экземпляр окна
	std::shared_ptr <Window> window(new WindowSFML);

	// устанавливаем размер
	window->setSize(size);

	// устанавливаем позицию
	sf::Vector2f position;

	// если стек окон пуст ставим стандартную позицию,
	// если не пуст - позицию самого верхнего окна + 35
	if (windowsStack->empty())
	{
		position.x = 400;
		position.y = 300;

	} else {

		position.x = windowsStack->back()->getPosition().x + 35;
		position.y = windowsStack->back()->getPosition().y + 35;
	}
	window->setPosition(position);

	// добавляем окно в стек
	windowsStack->push_back(window);
}

bool WindowManagerSFML::deleteWindow(const sf::Vector2i mousePosition)
{
	// если мышь над окном
	if (activeWindow)
	{
		// и находится над кнопкой закрытия окна
		if (windowsStack->at(activeWindow - 1)->getWidgetsStack()->at(2)->
			getGlobalBounds(mousePosition))
		{
			// удаляем активное окно из стека окон
			auto numberWindow = windowsStack->begin() + (activeWindow - 1);
			windowsStack->erase(numberWindow);
			activeWindow--;

			return true;
		}
	} 

	return false;
}

void WindowManagerSFML::moveWindow(const sf::Vector2i mousePosition, bool pressMouse)
{
	// если мышь над окном
	if (activeWindow)
	{
		// и находится над панелью окна
		if (windowsStack->at(activeWindow - 1)->getWidgetsStack()->
			at(1)->getGlobalBounds(mousePosition) || pressMouse)
		{
			sf::Vector2f newPosition;

			newPosition.x = mousePosition.x - windowsStack->at(activeWindow - 1)->
				getWidgetsStack()->at(1)->getSize().x / 2;

			newPosition.y = mousePosition.y - windowsStack->at(activeWindow - 1)->
				getWidgetsStack()->at(1)->getSize().y / 2;

			windowsStack->at(activeWindow - 1)->setPosition(newPosition);
		}
	}
}

// подъем окна на уровень вверх
void WindowManagerSFML::upWindow(const sf::Vector2i mousePosition)
{
	// если мышь над окном
	if (activeWindow)
	{
		// и окно не самое верхнее по уровню
		if (activeWindow < windowsStack->size())
		{
			// меняем уровень окна в стеке
			std::shared_ptr<Window> temp = windowsStack->at(activeWindow - 1);
			windowsStack->at(activeWindow - 1) = windowsStack->at(activeWindow);
			windowsStack->at(activeWindow) = temp;
		}
	}
}

// опускание окна на уровень вниз
void WindowManagerSFML::downWindow(const sf::Vector2i mousePosition)
{
	// если мышь не над самым нижним окном над окном
	if (activeWindow > 1)
	{
		// меняем уровень окна в стеке
		std::shared_ptr<Window> temp = windowsStack->at(activeWindow - 1);
		windowsStack->at(activeWindow - 1) = windowsStack->at(activeWindow - 2);
		windowsStack->at(activeWindow - 2) = temp;
	}
}

// отрисовка окон
void WindowManagerSFML::formingWindows()
{
	for (auto window : *windowsStack)
	{
		auto thisWindow = window->getWidgetsStack();

		thisWindow->at(0)->setOutlineThickness(3);
		thisWindow->at(0)->setOutlineColor(150, 150, 150);
		thisWindow->at(0)->setFillColor(255, 255, 255);
		thisWindow->at(1)->setFillColor(150, 150, 150);
		thisWindow->at(2)->setFillColor(50, 50, 50);
		thisWindow->at(3)->setFillColor(255, 255, 255);
		thisWindow->at(4)->setFillColor(255, 255, 255);
	}

	// выделение активного окна другим цветом
	if (activeWindow)
	{
		auto thisWindow = windowsStack->at(activeWindow - 1)->getWidgetsStack();

		thisWindow->at(0)->setOutlineColor(0, 149, 182);
		thisWindow->at(1)->setFillColor(0, 149, 182);
	}
}

// определение активного окна (над которым мышь)
int WindowManagerSFML::getActiveWindow(const sf::Vector2i mousePosition)
{
	activeWindow = 0;
	int countWindows = 0;

	for (auto window : *windowsStack)
	{
		countWindows++;

		if (window->getWidgetsStack()->at(0)->getGlobalBounds(mousePosition))
		{
			activeWindow = countWindows;
		}
	}

	return activeWindow;
}

std::shared_ptr <std::vector <std::shared_ptr <Window> > > 
	WindowManagerSFML::getWindowsStack()
{
	return windowsStack;
}