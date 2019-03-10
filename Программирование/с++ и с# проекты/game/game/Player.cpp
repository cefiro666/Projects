#include "pch.h"
#include "Player.h"

//класс платформ и текстовых полей счета игроков
Player::Player(float width, float height, float x, float y, float tx, float ty, string path_texture)
{
	this->width = width;
	this->height = height;
	platform.setSize(Vector2f(this->width, this->height));
	platform.setPosition(x, y);
	texture.loadFromFile(path_texture);
	platform.setTexture(&texture);
	speed = 15;
	score = 0;

	font.loadFromFile("fonts/LCDM2B__.TTF");
	t_score.setFont(font);
	t_score.setCharacterSize(300);
	t_score.setFillColor(Color(255, 255, 255, 60));
	t_score.setPosition(tx, ty);
}

//перемещения платформ
void Player::up()
{
	if (platform.getPosition().y >= 15) platform.move(0, -speed);
}

void Player::down()
{
	if (platform.getPosition().y <= 695 - height) platform.move(0, speed);
}