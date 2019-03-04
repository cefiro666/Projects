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
	bool direction_down;
	bool direction_right;
public:
	Ball(float radius, float x_position, float y_position, Color color);
	void x_offset(float x, RectangleShape &rectangle, float &width);
	void y_offset(float y);
	friend int main();
};