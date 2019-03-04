#include "pch.h"
#include "Player.h"

Player::Player(float width, float height, float x_position, float y_position, Color color)
{
	this->width = width;
	this->height = height;
	this->x_position = x_position;
	this->y_position = y_position;
	this->color = color;
	rectangle.setSize(Vector2f(width, height));
	rectangle.setPosition(x_position, y_position);
	rectangle.setFillColor(color);
}

void Player::up(float y)
{
	if (rectangle.getPosition().y >= y)
	{
		rectangle.move(0, -y);
	}
}

void Player::down(float y)
{
	if (rectangle.getPosition().y <= 600 - (height + y)) 
	{ 
		rectangle.move(0, y);
	}
}

