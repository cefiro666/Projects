#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Block.h"
#include "Tank.h"

using namespace std;
using namespace sf;

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 4;
	RenderWindow window(VideoMode(832, 832), " Tanks", Style::Default, settings);
	window.setFramerateLimit(60);

	Bullet bul(up, 150, 100);
	Tank tan;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		
		//bul.moveBullet();
		tan.moveTank();

		window.clear();
		window.draw(bul.bulletSprite);
		window.draw(tan.tankSprite);
		window.display();
	}
}