#include "pch.h"
#include "Ball.h"
#include "Player.h"
#include "Textbox.h"

int main()
{	//==========================================================
	//создание объектов игры для отрисовки
	
	Player left(45, 150, 50, 280, 255, 165, "images/left.png");
	Player right(45, 150, 1105, 280, 770, 165, "images/right.png");
	Ball ball(20, 580, 335, "images/ball.png");

	Textbox title(200, 120, 190, "Pong Game");
	Textbox press_start(50, 330, 450, "Press enter to start");
	Textbox left_guide(70, 180, 70, "Left player W / S");
	Textbox right_guide(70, 160, 550, "Right player Up / Down");
	Textbox pause_guide( 70, 380, 300, "Pause space");
	Textbox pause_text(100, 470, 300, "Pause");	

	//==========================================================
	//звуки
			
	SoundBuffer buffer_loos;
	buffer_loos.loadFromFile("sounds/loos.wav");
	Sound loos(buffer_loos);

	SoundBuffer buffer_repulse;
	buffer_repulse.loadFromFile("sounds/repulse.wav");
	Sound repulse(buffer_repulse);

	//==========================================================
	//таймеры

	Clock timer;
	Clock pause_timer;

	//==========================================================
	//создание окна, параметры окна

	ContextSettings settings;
	settings.antialiasingLevel = 4;
	RenderWindow window(VideoMode(1200, 710), " Pong", Style::Default, settings);
	window.setFramerateLimit(60);
	Image icon;
	icon.loadFromFile("images/icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());

	//==========================================================
	//задание текстуры для фона стартовой/справочной
	//и игровой сцен, установка стартового фона

	Texture start_texture;
	Texture game_texture;
	start_texture.loadFromFile("images/background_start.jpg");
	game_texture.loadFromFile("images/background_game.jpg");

	Sprite background;
	background.setTexture(start_texture);
	background.setPosition(0, 0);

	//==========================================================
	//булевы переменные

	bool start_scene = true;	// активность стартовая сцена
	bool guide_scene = false;	// активность справочная сцена
	bool game_scene = false;	// активность игровая сцена
	bool visible_start = true;	// видимость надписи Textbox press_start
	bool restart_timer = false;	// активность сброс таймера
	bool pause = false;			// активность пауза

	//==========================================================
	//главный игровой цикл

	while (window.isOpen())
	{
		//проверка событий окна
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//==========================================================
		//стартовая сцена

		if (start_scene)
		{
			//переход к следующей сцене по нажатию Enter
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				start_scene = false;
				guide_scene = true;
			}

			//мигание надписи
			Time time = timer.getElapsedTime();
			float delay = time.asSeconds();
			if (delay > 0.9)
			{
				if (visible_start)
				{
					visible_start = false;
					timer.restart();
				} else {
					visible_start = true;
					timer.restart();
				}
			}

			//отрисовка объектов
			window.clear();
			window.draw(background);
			window.draw(title.text);
			if (visible_start) window.draw(press_start.text);
			window.display();
		}

		//==========================================================
		//сцена справки

		if (guide_scene)
		{
			//переход к следующей сцене через 8 секунд или по нажатию Space
			Time time = timer.getElapsedTime();
			float delay = time.asSeconds();

			if (delay > 8 || Keyboard::isKeyPressed(Keyboard::Space))
			{
				guide_scene = false;
				game_scene = true;
				timer.restart();
				background.setTexture(game_texture);
				pause_timer.restart();
			}
			window.clear();
			window.draw(background);
			window.draw(left_guide.text);
			window.draw(pause_guide.text);
			window.draw(right_guide.text);
			window.display();
		}

		//==========================================================
		//игровая сцена

		if (game_scene)
		{
			//установка и обновление счета игроков
			left.t_score.setString(to_string(left.score));
			right.t_score.setString(to_string(right.score));

			//смещение при двузначной цифре счета
			if (left.score > 9) left.t_score.setPosition(160, 165);
			if (right.score > 9) right.t_score.setPosition(700, 165);

			//таймер паузы в 2 секунды перед началом раунда
			Time time = timer.getElapsedTime();
			float delay = time.asSeconds();
			if (!restart_timer && !ball.motion)
			{
				timer.restart();
				restart_timer = true;
			}
			if (delay > 2)
			{
				if (!ball.motion) ball.motion = true;
				timer.restart();
				restart_timer = false;
			}

			//управление платформами
			if (!pause) {
				if (Keyboard::isKeyPressed(Keyboard::W)) left.up();
				if (Keyboard::isKeyPressed(Keyboard::S)) left.down();
				if (Keyboard::isKeyPressed(Keyboard::Up)) right.up();
				if (Keyboard::isKeyPressed(Keyboard::Down)) right.down();
			}

			//перемещение мяча
			if (ball.motion && !pause)
			{
				ball.x_offset(left, right, loos, repulse);
				ball.y_offset(repulse);
			}

			//пауза
			if (Keyboard::isKeyPressed(Keyboard::Space) && !pause)
			{
				Time time = pause_timer.getElapsedTime();
				float delay = time.asSeconds();
				if (delay > 0.5) pause = true;
				pause_timer.restart();
			} 
			if (Keyboard::isKeyPressed(Keyboard::Space) && pause)
			{	
				Time time = pause_timer.getElapsedTime();
				float delay = time.asSeconds();
				if (delay > 0.5) pause = false;
				pause_timer.restart();
			}

			//отрисовка объектов
			window.clear();
			window.draw(background);
			window.draw(left.t_score);
			window.draw(right.t_score);
			window.draw(ball.circle);
			window.draw(left.platform);
			window.draw(right.platform);
			if (pause) window.draw(pause_text.text);
			window.display();
		}
	}
}