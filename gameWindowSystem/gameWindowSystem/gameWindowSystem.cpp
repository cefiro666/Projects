#include "WindowManagerSFML.h"

int main()
{
	// создаем "эмулятор" displayServer
	sf::RenderWindow display;
	display.create(sf::VideoMode(1280, 768), "display", sf::Style::Close);

	// создаем рабочий стол с папкой для красоты
	// ================================================
	sf::Texture wallpaper;
	wallpaper.loadFromFile("desktop.png");

	sf::RectangleShape desktop;
	desktop.setSize(sf::Vector2f(display.getSize()));
	desktop.setTexture(&wallpaper);
	desktop.setPosition(sf::Vector2f(0, 0));

	sf::Texture iconTex;
	iconTex.loadFromFile("folder.png");

	sf::RectangleShape icon;
	icon.setTexture(&iconTex);
	icon.setSize(sf::Vector2f(100,70));
	icon.setPosition(sf::Vector2f(70, 50));
	// ================================================

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
					// попытаться удалить окно (если щелчок по кнопке закрытия)
					if (!windowManager->deleteWindow(mousePosition))
					{
						// если удаления не было, то создать окно (если щелчок по значку)
						if (icon.getGlobalBounds().contains(sf::Vector2f(mousePosition))
							&& windowManager->getActiveWindow(mousePosition) == 0)
						{
							windowManager->createWindow(sf::Vector2f(400, 300));
						}

						// выставить контроль мыши и разрешить движение окна
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

		display.draw(desktop);
		display.draw(icon);

		for (auto window : *(windowManager->getWindowsStack()))
		{
			for (auto widget : *(window->getWidgetsStack()))
			{
				auto rectangle = *(widget->getRectangle());
				display.draw(rectangle);
			}
		}

		display.display();
		// ==================================================
	}
}