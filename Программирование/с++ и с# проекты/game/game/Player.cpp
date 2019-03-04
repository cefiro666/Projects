#include "pch.h"
#include "Player.h"

Player::Player(float width, float height, float x_position, float y_position, Color color, float x_text, float y_text)
{
	this->width = width;
	this->height = height;
	rectangle.setSize(Vector2f(width, height));
	rectangle.setPosition(x_position, y_position);
	rectangle.setFillColor(color);

	text_score.setCharacterSize(50);
	font_text.loadFromFile("fonts/LCDM2B__.TTF");
	text_score.setFont(font_text);
	text_score.setPosition(x_text, y_text);
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

