#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Tank
{
private:
	int healtPoints;
	Image tankImage;
	Texture tankTexture;
	Clock clock;
	float animation_time;

public:
	Sprite tankSprite;

	Tank();

	void moveTank();

	~Tank();

};

