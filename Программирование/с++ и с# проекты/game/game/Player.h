#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class Player
{
private:
	RectangleShape rectangle;
	float width;
	float height;

	int score = 0;
	Text text_score;
	Font font_text;
	string string_score;
	
public:
	Player(float width, float height, float x_position, float y_position, Color color, float x_text, float y_text);
	void down(float y);
	void up(float y);

	friend class Ball;
	friend int main();
};