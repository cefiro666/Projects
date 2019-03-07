//класс игроков (параметры и управление платформ, очки)
#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Player
{
private:	
	float width;
	float height;
	RectangleShape platform;
	Texture texture;
	int score;
	Text text_score;
	Font font_text;
	string string_score;
	float speed;

public:
	Player(float width, float height, float x, float y, float x_text, float y_text, string path_texture);
	void down();
	void up();
	friend class Ball;
	friend int main();
};