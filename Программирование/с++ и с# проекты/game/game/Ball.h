#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

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
public:

	Ball(float radius, float x_position, float y_position, Color color);
	void x_offset(float x, RectangleShape& left, RectangleShape& right, float& left_width, float& left_height, float& right_width, float& right_height);
	void y_offset(float y);
	friend int main();
};