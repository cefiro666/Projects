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
	
	Bullet(direction d, float xPos, float yPos)
	{
		bulletImage.loadFromFile("images/texture.png");
		bulletImage.createMaskFromColor(Color(255, 0, 255));
		bulletTexture.loadFromImage(bulletImage);
		bulletSprite.setTexture(bulletTexture);
		dir = d;

		if (dir == direction::up)
		{
			bulletSprite.setTextureRect(IntRect(192, 0, 12, 16));
		} else if (dir == direction::down) 
		{
			bulletSprite.setTextureRect(IntRect(192, 32, 12, 16));
		} else if (dir == direction::left) 
		{
			bulletSprite.setTextureRect(IntRect(224, 0, 16, 12));
		} else if (dir == direction::right) 
		{
			bulletSprite.setTextureRect(IntRect(224, 32, 16, 12));
		}

		bulletSprite.setPosition(xPos, yPos);
	}

	void moveBullet()
	{
		if (dir == direction::up)
		{
			bulletSprite.move(0, -1);
		} else if (dir == direction::down)
		{
			bulletSprite.move(0, 1);
		} else if (dir == direction::left)
		{
			bulletSprite.move(1, 0);
		} else if (dir == direction::right)
		{
			bulletSprite.move(-1, 0);
		}
	}

	~Bullet();
};

