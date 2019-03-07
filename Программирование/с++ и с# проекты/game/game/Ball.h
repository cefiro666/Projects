#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

class Ball
{
private:	
	float radius;
	CircleShape circle;
	Texture texture;
	bool direction_down;
	bool direction_right;
	bool false_repulse;
	bool start;
	bool restart_timer;
	float x_speed;
	float y_speed;

public:
	Ball(float radius, float x_shape, float y_shape, string path_texture);
	void x_offset(Player& left, Player& right);
	void y_offset();
	friend int main();
};