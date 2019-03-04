#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Ball.h"

using namespace sf;

class Player
{
private:
	RectangleShape rectangle;
	float width;
	float height;
	float x_position;
	float y_position;
	Color color;
	
public:
	Player(float width, float height, float x_position, float y_position, Color color);
	void down(float y);
	void up(float y);
	friend void Ball::x_offset(float x, RectangleShape &rectangle, float &width);
	friend int main();
};