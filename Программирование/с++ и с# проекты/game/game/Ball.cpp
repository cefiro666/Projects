#include "pch.h"
#include "Ball.h"

Ball::Ball(float radius, float x_shape, float y_shape, Color color)
{
	this->radius = radius;
	circle.setRadius(this->radius);
	circle.setPosition(x_shape, y_shape);
	circle.setFillColor(color);
}

void Ball::x_offset(float x, Player& left, Player& right)
{
	if (direction_right && circle.getPosition().x + radius * 2 <= 1100)
	{
		circle.move(x, 0);
	}

	if (direction_right && circle.getPosition().x + radius * 2 >= 1100)
	{
		circle.setPosition(1000 / 2, 600 / 2);
		direction_right = false;
		false_repulse = false;
		left.score++;
		start = false;
	}

	if (!direction_right && circle.getPosition().x >= -100)
	{
		circle.move(-x, 0);
	}

	if (!direction_right && circle.getPosition().x <= -100)
	{
		circle.setPosition(1000 / 2, 600 / 2);
		direction_right = true;
		false_repulse = false;
		right.score++;
		start = false;
	}

	//проверка на ложное отбитие
	if ((circle.getPosition().x <= left.platform.getPosition().x + left.width &&
		!(circle.getPosition().y + radius >= left.platform.getPosition().y &&
			circle.getPosition().y + radius <= left.platform.getPosition().y + left.height)) ||
		(circle.getPosition().x + radius * 2 >= right.platform.getPosition().x &&
			!(circle.getPosition().y + radius >= right.platform.getPosition().y &&
				circle.getPosition().y + radius <= right.platform.getPosition().y + right.height)))
	{
		false_repulse = true;
	}
	if (!false_repulse && circle.getPosition().x + (radius * 2) >= right.platform.getPosition().x &&
		circle.getPosition().y + radius * 2 >= right.platform.getPosition().y &&
		circle.getPosition().y <= right.platform.getPosition().y + right.height)
	{
		direction_right = false;
	}

	if (!false_repulse && circle.getPosition().x <= left.platform.getPosition().x + left.width &&
		circle.getPosition().y + radius * 2 >= left.platform.getPosition().y &&
		circle.getPosition().y <= left.platform.getPosition().y + left.height)
	{
		direction_right = true;
	}
}

void Ball::y_offset(float y)
{
	if (direction_down && circle.getPosition().y <= 600)
	{
		circle.move(0, y);
	}

	if (!direction_down && circle.getPosition().y >= 0)
	{
		circle.move(0, -y);
	}

	if (circle.getPosition().y <= 0)
	{
		direction_down = true;
	}

	if (circle.getPosition().y >= (600 - (radius * 2)))
	{
		direction_down = false;
	}
}