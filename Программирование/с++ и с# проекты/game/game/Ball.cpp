#include "pch.h"
#include "Ball.h"
#include "Player.h"

Ball::Ball(float radius, float x_position, float y_position, Color color)
{
	this->radius = radius;
	this->x_position = x_position;
	this->y_position = y_position;
	this->color = color;
	shape.setRadius(radius);
	shape.setPosition(x_position, y_position);
	shape.setFillColor(color);
}

void Ball::x_offset(float x, RectangleShape& left, RectangleShape& right, float& left_width, float& left_height, float& right_width, float& right_height)
{
	if (direction_right && shape.getPosition().x + radius * 2 <= 1000)
	{
		shape.move(x, 0);
	}

	if (direction_right && shape.getPosition().x + radius * 2 >= 1000)
	{
		shape.setPosition(1000 / 2, 600 / 2);
		direction_right = false;
		false_repulse = false;
	}

	if (!direction_right && shape.getPosition().x >= 0)
	{
		shape.move(-x, 0);
	}

	if (!direction_right && shape.getPosition().x <= 0)
	{
		shape.setPosition(1000 / 2, 600 / 2);
		direction_right = true;
		false_repulse = false;
	}
	//проверка на ложное отбитие
	if ((shape.getPosition().x <= left.getPosition().x + left_width && 
		!(shape.getPosition().y + radius >= left.getPosition().y && shape.getPosition().y + radius <= left.getPosition().y + left_height)) || 
		(shape.getPosition().x + radius * 2 >= right.getPosition().x && !(shape.getPosition().y + radius >= right.getPosition().y && 
			shape.getPosition().y + radius <= right.getPosition().y + right_height))) 
	{
		false_repulse = true;
	}
	if (!false_repulse && shape.getPosition().x + (radius * 2) >= right.getPosition().x && 
		shape.getPosition().y + radius >= right.getPosition().y && shape.getPosition().y + radius <= right.getPosition().y + right_height)
	{
		direction_right = false;
	}

	if (!false_repulse && shape.getPosition().x <= left.getPosition().x + left_width && 
		shape.getPosition().y + radius >= left.getPosition().y && shape.getPosition().y + radius <= left.getPosition().y + left_height)
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