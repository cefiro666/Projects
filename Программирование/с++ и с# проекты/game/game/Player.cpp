#include "pch.h"
#include "Player.h"

Player::Player(float width, float height, float x_position, float y_position, Color color)
{
	rectangle.setSize(Vector2f(width, height));
	rectangle.setPosition(x_position, y_position);
	rectangle.setFillColor(color);
}

void Player::down(float y)
{
	if (rectangle.getPosition().y <= 100 - this->height)
	{
		rectangle.move(0, y);
	}
}
void Player::up(float y)
{
	if (rectangle.getPosition().y >= 0)
	{
		rectangle.move(0, -y);
	}
}