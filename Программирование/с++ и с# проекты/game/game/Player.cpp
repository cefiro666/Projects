#include "pch.h"
#include "Player.h"

Player::Player(float width, float height, float x, float y, float x_text, float y_text, string path_texture)
{
	this->width = width;
	this->height = height;
	score = 0;
	string_score = to_string(score);
	platform.setSize(Vector2f(this->width, this->height));
	platform.setPosition(x, y);
	texture.loadFromFile(path_texture);
	platform.setTexture(&texture);
	font_text.loadFromFile("fonts/LCDM2B__.TTF");
	text_score.setFont(font_text);
	text_score.setCharacterSize(300);
	text_score.setFillColor(Color(255, 255, 255, 60));
	text_score.setPosition(x_text, y_text);
	text_score.setString(string_score);
	speed = 15;
}

void Player::up()
{
	if (platform.getPosition().y >= 15) {platform.move(0, -speed);}
}

void Player::down()
{
	if (platform.getPosition().y <= 695 - height) {platform.move(0, speed);}
}

