#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum direction { up, down, left, right };

class Bullet
{
private:
	int speed;
	Image bulletImage;
	Texture bulletTexture;
	direction dir;

public:
	Sprite bulletSprite;
	
	Bullet(direction d, float xPos, float yPos);

	void moveBullet();

	~Bullet();
};

