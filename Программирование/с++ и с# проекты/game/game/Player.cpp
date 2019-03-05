#include "pch.h"
#include "Player.h"

Player::Player(float width, float height, float x_platform, float y_platform, Color color, float x_text, float y_text)
{
	this->width = width;
	this->height = height;
	this->score = 0;
	platform.setSize(Vector2f(this->width, this->height));
	platform.setPosition(x_platform, y_platform);
	platform.setFillColor(color);
	
	font_text.loadFromFile("fonts/LCDM2B__.TTF");
	text_score.setFont(font_text);
	text_score.setCharacterSize(50);
	text_score.setPosition(x_text, y_text);
}

void Player::up(float y)
{
	if (platform.getPosition().y >= y)
	{
		platform.move(0, -y);
	}
}

void Player::down(float y)
{
	if (platform.getPosition().y <= 600 - (height + y))
	{ 
		platform.move(0, y);
	}
}

