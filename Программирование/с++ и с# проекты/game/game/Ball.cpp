#include "pch.h"
#include "Ball.h"

Ball::Ball(float radius, float x_shape, float y_shape, Color color)
{
	this->radius = radius;
	shape.setRadius(this->radius);
	shape.setPosition(x_shape, y_shape);
	shape.setFillColor(color);
}

void Ball::x_offset(float x, Player& left, Player& right)
{
	if (direction_right && shape.getPosition().x + radius * 2 <= 1100)
	{
		shape.move(x, 0);
	}

	if (direction_right && shape.getPosition().x + radius * 2 >= 1100)
	{
		shape.setPosition(1000 / 2, 600 / 2);
		direction_right = false;
		false_repulse = false;
		left.score++;
		start = false;
	}

	if (!direction_right && shape.getPosition().x >= -100)
	{
		shape.move(-x, 0);
	}

	if (!direction_right && shape.getPosition().x <= -100)
	{
		shape.setPosition(1000 / 2, 600 / 2);
		direction_right = true;
		false_repulse = false;
		right.score++;
		start = false;
	}

	//проверка на ложное отбитие
	if ((shape.getPosition().x <= left.platform.getPosition().x + left.width &&
		!(shape.getPosition().y + radius >= left.platform.getPosition().y &&
			shape.getPosition().y + radius <= left.platform.getPosition().y + left.height)) ||
		(shape.getPosition().x + radius * 2 >= right.platform.getPosition().x &&
			!(shape.getPosition().y + radius >= right.platform.getPosition().y &&
			shape.getPosition().y + radius <= right.platform.getPosition().y + right.height)))
	{
		false_repulse = true;
	}
	if (!false_repulse && shape.getPosition().x + (radius * 2) >= right.platform.getPosition().x &&
		shape.getPosition().y + radius * 2 >= right.platform.getPosition().y &&
		shape.getPosition().y <= right.platform.getPosition().y + right.height)
	{
		direction_right = false;
	}

	if (!false_repulse && shape.getPosition().x <= left.platform.getPosition().x + left.width &&
		shape.getPosition().y + radius * 2 >= left.platform.getPosition().y &&
		shape.getPosition().y <= left.platform.getPosition().y + left.height)
	{
		direction_right = true;
	}
}

void Ball::y_offset(float y)
{
	if (direction_down && shape.getPosition().y <= 600)
	{
		shape.move(0, y);
	}

	if (!direction_down && shape.getPosition().y >= 0)
	{
		shape.move(0, -y);
	}

	if (shape.getPosition().y <= 0) 
	{
		direction_down = true;
	}

	if (shape.getPosition().y >= (600 - (radius * 2)))
	{
		direction_down = false;
	}
}