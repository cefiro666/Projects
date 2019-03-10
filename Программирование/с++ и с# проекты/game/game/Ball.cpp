#include "pch.h"
#include "Ball.h"

Ball::Ball(float radius, float x, float y, string path_texture)
{
	this->radius = radius;
	circle.setRadius(this->radius);
	circle.setPosition(x, y);
	texture.loadFromFile(path_texture);
	circle.setTexture(&texture);
	color = 128;
	circle.setFillColor(Color(color, 0, 255, 255));
	direction_down = true;
	direction_right = true;
	false_repulse = false;
	start = false;
	x_speed = 10;
	y_speed = 5;
}

void Ball::x_offset(Player& left, Player& right, Sound& loos, Sound& repulse)
{
	//перемещение шарика вправо
	if (direction_right && circle.getPosition().x + radius * 2 <= 1300)
	{
		circle.move((fabs(static_cast<float>(x_speed))), 0);
		color += 2;
		circle.setFillColor(Color(color, 0, 255, 255));
	}

	//перемещение шарика влево
	if (!direction_right && circle.getPosition().x >= -100)
	{
		circle.move(-(fabs(static_cast<float>(x_speed))), 0);
		color -= 2;
		circle.setFillColor(Color(color, 0, 255, 255));
	}
	
	//уход шарика за правый край (гол)
	if (direction_right && circle.getPosition().x + radius * 2 >= 1300)
	{
		loos.play();
		circle.setPosition(580, 335);
		direction_right = false;
		false_repulse = false;
		start =	false;
		left.score++;
		x_speed = 10;
		y_speed = 5;
		color = 128;
		circle.setFillColor(Color(color, 0, 255, 255));	
	}
	
	//уход шарика за левый край (гол)
	if (!direction_right && circle.getPosition().x <= -100)
	{
		loos.play();
		circle.setPosition(580, 335);
		direction_right = true;
		false_repulse = false;
		start = false;
		right.score++;
		x_speed = 10;
		y_speed = 5;
		color = 128;
		circle.setFillColor(Color(color, 0, 255, 255));
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
		//изменение скоростей по x и y в зависимости от движения платформы во время удара
		if (direction_down && Keyboard::isKeyPressed(Keyboard::Down))
		{
			delta_y = static_cast<float>(1 + rand() % 3);
			delta_x = static_cast<float>(0 + rand() % 2);
			y_speed += delta_y;
			x_speed += delta_x;
		}
		if (!direction_down && Keyboard::isKeyPressed(Keyboard::Down))
		{
			delta_y = static_cast<float>(1 + rand() % 3);
			delta_x = static_cast<float>(0 + rand() % 2);
			y_speed -= delta_y;
			x_speed += delta_x;
		}
		if (direction_down && Keyboard::isKeyPressed(Keyboard::Up))
		{
			delta_y = static_cast<float>(1 + rand() % 3);
			delta_x = static_cast<float>(0 + rand() % 2);
			y_speed -= delta_y;
			x_speed += delta_x;
		}
		if (!direction_down && Keyboard::isKeyPressed(Keyboard::Up))
		{
			delta_y = static_cast<float>(1 + rand() % 3);
			delta_x = static_cast<float>(0 + rand() % 2);
			y_speed += delta_y;
			x_speed += delta_x;
		}
		repulse.play();
		direction_right = false;
	}

	//отбитие левой платформы
	if (!false_repulse && circle.getPosition().x <= left.platform.getPosition().x + left.width &&
		circle.getPosition().y + (radius * 2) + 10 >= left.platform.getPosition().y &&
		circle.getPosition().y - 10 <= left.platform.getPosition().y + left.height)
	{
		//изменение скоростей по x и y в зависимости от движения платформы во время удара
		if (direction_down && Keyboard::isKeyPressed(Keyboard::S))
		{
			delta_y = static_cast<float>(1 + rand() % 3);
			delta_x = static_cast<float>(0 + rand() % 2);
			y_speed += delta_y;
			x_speed += delta_x;
		}
		if (!direction_down && Keyboard::isKeyPressed(Keyboard::S))
		{
			delta_y = static_cast<float>(1 + rand() % 3);
			delta_x = static_cast<float>(0 + rand() % 2);
			y_speed -= delta_y;
			x_speed += delta_x;
		}
		if (direction_down && Keyboard::isKeyPressed(Keyboard::W))
		{
			delta_y = static_cast<float>(1 + rand() % 3);
			delta_x = static_cast<float>(0 + rand() % 2);
			y_speed -= delta_y;
			x_speed += delta_x;
		}
		if (!direction_down && Keyboard::isKeyPressed(Keyboard::W))
		{
			delta_y = static_cast<float>(1 + rand() % 3);
			delta_x = static_cast<float>(0 + rand() % 2);
			y_speed += delta_y;
			x_speed += delta_x;
		}
		repulse.play();
		direction_right = true;
	}
}

//смещение по y 
void Ball::y_offset(Sound& repulse)
{
	//перемещение вниз
	if (direction_down && circle.getPosition().y + (radius * 2) <= 710)
	{
		circle.move(0, (fabs(static_cast<float>(y_speed))));
	}

	//перемещение вверх
	if (!direction_down && circle.getPosition().y >= 0)
	{
		circle.move(0, -(fabs(static_cast<float>(y_speed))));
	}

	//отскок от верха
	if (circle.getPosition().y <= 0)
	{
		if (!false_repulse) repulse.play();
		direction_down = true;
	}

	//отскок от низа
	if (circle.getPosition().y + (radius * 2) >= 710)
	{
		if (!false_repulse) repulse.play();
		direction_down = false;
	}
}