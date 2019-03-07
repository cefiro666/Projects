#include "pch.h"
#include "Ball.h"

Ball::Ball(float radius, float x_shape, float y_shape, string path_texture)
{
	this->radius = radius;
	circle.setRadius(this->radius);
	circle.setPosition(x_shape, y_shape);
	texture.loadFromFile(path_texture);
	circle.setTexture(&texture);
	direction_down = true;
	direction_right = true;
	false_repulse = false;
	restart_timer = true;
	start = false;
	x_speed = 15;
	y_speed = 5;
	buffer_repulse.loadFromFile("sounds/Tap_on_M-Sapphire-8662_hifi.wav");
	sound_repulse.setBuffer(buffer_repulse);
	buffer_loos.loadFromFile("sounds/Switch19-intermed-5284_hifi.wav");
	sound_loos.setBuffer(buffer_loos);
}

void Ball::x_offset(Player& left, Player& right)
{
	//перемещение шарика вправо
	if (direction_right && circle.getPosition().x + radius * 2 <= 1300)
	{
		circle.move((fabs(static_cast<double>(x_speed))), 0);
	}
	
	//уход шарика за правый край (гол)
	if (direction_right && circle.getPosition().x + radius * 2 >= 1300)
	{
		sound_loos.play();
		circle.setPosition(580, 335);
		direction_right = false;
		false_repulse = false;
		left.score++;
		left.string_score = to_string(left.score);
		start = false;
		restart_timer = true;
		x_speed = 15;
		y_speed = 5;
	}
	
	//перемещение шарика влево
	if (!direction_right && circle.getPosition().x >= -100)
	{
		circle.move(-(fabs(static_cast<double>(x_speed))), 0);
	}
	
	//уход шарика за левый край (гол)
	if (!direction_right && circle.getPosition().x <= -100)
	{
		sound_loos.play();
		circle.setPosition(580, 335);
		direction_right = true;
		false_repulse = false;
		right.score++;
		right.string_score = to_string(right.score);
		start = false;
		restart_timer = true;
		x_speed = 15;
		y_speed = 5;
	}

	//проверка на ложное отбитие (когда шарик отбивается, хотя залетел за платформу)
	if ((circle.getPosition().x <= left.platform.getPosition().x + left.width &&
		!(circle.getPosition().y + radius * 2 + 10 >= left.platform.getPosition().y &&
		circle.getPosition().y - 10 <= left.platform.getPosition().y + left.height)) ||
		(circle.getPosition().x + radius * 2 >= right.platform.getPosition().x &&
		!(circle.getPosition().y + radius * 2 + 10 >= right.platform.getPosition().y &&
		circle.getPosition().y - 10 <= right.platform.getPosition().y + right.height)))
	{
		false_repulse = true;
	}

	//отбитие правой платформы
	if (!false_repulse && circle.getPosition().x + (radius * 2) >= right.platform.getPosition().x &&
		circle.getPosition().y + (radius * 2) + 10 >= right.platform.getPosition().y &&
		circle.getPosition().y - 10 <= right.platform.getPosition().y + right.height)
	{
		if (direction_down && Keyboard::isKeyPressed(Keyboard::Down))
		{
			delta = 1 + rand() % 3;
			y_speed += delta;
			x_speed -= delta;
		}
		if (!direction_down && Keyboard::isKeyPressed(Keyboard::Down))
		{
			delta = 1 + rand() % 3;
			y_speed -= delta;
			x_speed += delta;
		}
		if (direction_down && Keyboard::isKeyPressed(Keyboard::Up))
		{
			delta = 1 + rand() % 3;
			y_speed -= delta;
			x_speed += delta;
		}
		if (!direction_down && Keyboard::isKeyPressed(Keyboard::Up))
		{
			delta = 1 + rand() % 3;
			y_speed += delta;
			x_speed -= delta;
		}
		sound_repulse.play();
		direction_right = false;
	}

	//отбитие левой платформы
	if (!false_repulse && circle.getPosition().x <= left.platform.getPosition().x + left.width &&
		circle.getPosition().y + (radius * 2) + 10 >= left.platform.getPosition().y &&
		circle.getPosition().y - 10 <= left.platform.getPosition().y + left.height)
	{
		if (direction_down && Keyboard::isKeyPressed(Keyboard::S))
		{
			delta = 1 + rand() % 3;
			y_speed += delta;
			x_speed -= delta;
		}
		if (!direction_down && Keyboard::isKeyPressed(Keyboard::S))
		{
			delta = 1 + rand() % 3;
			y_speed -= delta;
			x_speed += delta;
		}
		if (direction_down && Keyboard::isKeyPressed(Keyboard::W))
		{
			delta = 1 + rand() % 3;
			y_speed -= delta;
			x_speed += delta;
		}
		if (!direction_down && Keyboard::isKeyPressed(Keyboard::W))
		{
			delta = 1 + rand() % 3;
			y_speed += delta;
			x_speed -= delta;
		}
		sound_repulse.play();
		direction_right = true;
	}
}

void Ball::y_offset()
{
	if (direction_down && circle.getPosition().y + (radius * 2) <= 710)
	{
		circle.move(0, (fabs(static_cast<double>(y_speed))));
	}

	if (!direction_down && circle.getPosition().y >= 0)
	{
		circle.move(0, -(fabs(static_cast<double>(y_speed))));
	}

	if (circle.getPosition().y <= 0)
	{
		if (!false_repulse)
		{
			sound_repulse.play();
		}
		direction_down = true;
	}

	if (circle.getPosition().y + (radius * 2) >= 710)
	{
		if (!false_repulse)
		{
			sound_repulse.play();
		}
		direction_down = false;
	}
}