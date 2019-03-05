#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

class Player
{
private:	
	float width;
	float height;
	RectangleShape platform;

	int score;
	Text text_score;
	Font font_text;
	string string_score;
	
public:
	Player(float width, float height, float x_platform, float y_platform, Color color, float x_text, float y_text);
	void down(float y);
	void up(float y);

	friend class Ball;
	friend int main();
};