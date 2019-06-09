#include "WindowManagerSFML.h"

int main()
{
	// создаем "эмулятор" displayServer
	sf::RenderWindow display;
	display.create(sf::VideoMode(1280, 768), "display", sf::Style::Close);

	// создаем "оконный менеджер"
	std::shared_ptr<WindowManager> windowManager(new WindowManagerSFML);

	// контроль положения мыши и движения окна
	bool moveWindow = false;
	bool pressMouse = false;

	while (display.isOpen())
	{
		// определили положение мыши
		auto mousePosition = sf::Mouse::getPosition(display);

		// определили активное окно, если не нажата мышь
		if (!pressMouse) windowManager->getActiveWindow(mousePosition);

		sf::Event event;
		while (display.pollEvent(event))
		{
			//         События в системе и их обработка
			// ================================================

			// закончить работу displayServer
			// ================================================
			if (event.type == sf::Event::Closed) display.close();
			
			// при отжатии кнопки мыши прекратить движение окна
			// =================================================
			if (event.type == sf::Event::MouseButtonReleased)
			{
				pressMouse = false;
				moveWindow = false;
			}

			// по нажатию N создать новое окно
			// =================================================
			if (event.type == sf::Event::KeyPressed && !pressMouse)
			{
				if (event.key.code == sf::Keyboard::N)
				{
					windowManager->createWindow(sf::Vector2f(400, 300));
				}
			}

			// по нажатию Down опустить окно на уровень ниже
			// =================================================
			if (event.type == sf::Event::KeyPressed && !pressMouse)
			{
				if (event.key.code == sf::Keyboard::Down)
				{
					windowManager->downWindow(mousePosition);
				}
			}

			// по нажатию Up поднять окно на уровень выше
			// =================================================
			if (event.type == sf::Event::KeyPressed && !pressMouse)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					windowManager->upWindow(mousePosition);
				}
			}

			// по нажатию на левую кнопку мыши
			// =================================================
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					// попытаться удалить окно
					if (!windowManager->deleteWindow(mousePosition))
					{
						// если удаления не было выставить контроль
						// мыши и разрешить движение окна
						pressMouse = true;
						moveWindow = true;
					}	
				}
			}

			// переместить окно, если нажата кнопка мыши и она над панелью окна
			// ==================================================
			if (moveWindow) windowManager->moveWindow(mousePosition, pressMouse);
			// ==================================================
		}

		// формирование окон
		windowManager->formingWindows();

		// отрисовка окон
		// ==================================================
		display.clear();

		for (auto window : *(windowManager->getWindowsStack()))
		{
			for (auto widget : *(window->getWidgetsStack()))
			{
				for (auto thisWidget : *(widget->getWidget()))
				{
					display.draw(*thisWidget);
				}
			}
		}

		display.display();
		// ==================================================
	}
}