#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace sf;
using namespace std;

class Player;
class Ball
{
private:
	CircleShape shape;
	float radius;
	float x_position;
	float y_position;
	Color color;

	bool direction_down = true;
	bool direction_right = true;
	bool false_repulse = false;
	bool start = false;

public:

	Ball(float radius, float x_position, float y_position, Color color);
	void x_offset(float x, Player& left, Player& right);
	void y_offset(float y);
	friend int main();
};