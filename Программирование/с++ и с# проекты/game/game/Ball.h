#pragma once

#include <SFML/Audio.hpp>
#include "Player.h"

//класс м€ча (движение, голы, звуки)
class Ball
{
private:	
	float radius;
	float x_speed;
	float y_speed;
	float delta_x;
	float delta_y;
	int color;
	bool direction_down;
	bool direction_right;
	bool false_repulse;
	bool start;
	CircleShape circle;
	Texture texture;

public:
	Ball(float radius, float x, float y, string path_texture);
	void x_offset(Player& left, Player& right, Sound& loss, Sound& repulse);
	void y_offset(Sound& repulse);
	friend int main();
};