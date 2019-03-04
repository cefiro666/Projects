#include "pch.h"
#include "Ball.h"
#include "Player.h"

Ball::Ball(float radius, float x_position, float y_position, Color color)
{
	shape.setRadius(radius);
	shape.setPosition(x_position, y_position);
	shape.setFillColor(color);
}

void Ball::x_offset(float x, RectangleShape &rectangle, float &width)
{
	if (direction_right && shape.getPosition().x <= 1000)
	{
		shape.move(x, 0);
	}

	if (!direction_right && shape.getPosition().x >= 0)
	{
		shape.move(-x, 0);
	}

	if (shape.getPosition().x <= 0)
	{
		shape.setPosition(1000 / 2, 600 / 2);
		direction_right = true;
	}

	if (shape.getPosition().x >= 1000) 
	{
		shape.setPosition(1000 / 2, 600 / 2);
		direction_right = false;
	}

	if (direction_right && (shape.getPosition().x + radius) >= rectangle.getPosition().x)
	{
		direction_right = false;
	}

	if (!direction_right && shape.getPosition().x <= (rectangle.getPosition().x + width))
	{
		direction_right = true;
	}
}

void Ball::y_offset(float y)
{
	if (direction_down && shape.getPosition().y <= 600)
	{
		shape.move(y, 0);
	}

	if (!direction_down && shape.getPosition().y >= 0)
	{
		shape.move(-y, 0);
	}

	if (shape.getPosition().y <= 0) 
	{
		direction_down = true;
	}

	if (shape.getPosition().y >= 600) 
	{
		direction_down = false;
	}
}