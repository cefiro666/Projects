#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

//класс платформ и текстовых полей счета игроков
class Player
{
private:	
	float width;
	float height;
	float speed;
	RectangleShape platform;
	Texture texture;
	int score;
	Font font;
	Text t_score;

public:
	Player(float width, float height, float x, float y, float tx, float ty, string path_texture);
	void down();
	void up();
	friend class Ball;
	friend int main();
};