#include "pch.h"
#include "Ball.h"
#include "Player.h"

int main()
{	
	//объекты игры и таймер
	Player left(45, 150, 50, 280, 255, 165, "images/left.png");
	Player right(45, 150, 1105, 280, 770, 165, "images/right.png");
	Ball ball(20, 580, 335, "images/ball.png");
	Clock timer;

	//создание окна, параметры окна
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(1200, 710), " Pong", Style::Default, settings);
	window.setFramerateLimit(60);
	Image icon;
	icon.loadFromFile("images/icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());

	//задание текстуры для фона игрового поля
	Texture texture;
	texture.loadFromFile("images/background.jpg");
	Sprite background;
	background.setTexture(texture);
	background.setPosition(0, 0);

	while (window.isOpen())
	{	
		//проверка событий окна
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		//установка и обновление счета игрока
		left.text_score.setString(left.string_score);
		right.text_score.setString(right.string_score);
		if (left.score > 9) {
			left.text_score.setPosition(160, 165);
		}
		if (right.score > 9) {
			right.text_score.setPosition(700, 165);
		}

		//таймер паузы в 3 секунды при рестарте
		Time time = timer.getElapsedTime();
		float pause = time.asSeconds();
		if (ball.restart_timer)
		{
			timer.restart();
			ball.restart_timer = false;
		}
		if (pause > 3)
		{
			ball.start = true;
			timer.restart();
		}
		
		//управление платформами
		if (Keyboard::isKeyPressed(Keyboard::W)) {left.up();}
		if (Keyboard::isKeyPressed(Keyboard::S)) {left.down();}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {right.up();}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {right.down();}
		
		//перемещение мяча
		if (ball.start) {
			ball.x_offset(left, right);
			ball.y_offset();
		}

		cout << ball.y_speed << "   " << ball.direction_down << endl;

		//отрисовка объектов
		window.clear();	
		window.draw(background);
		window.draw(left.text_score);
		window.draw(right.text_score);	
		window.draw(ball.circle);
		window.draw(left.platform);
		window.draw(right.platform);
		window.display();
	}
}
