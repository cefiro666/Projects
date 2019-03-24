#include "pch.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 4;
	RenderWindow window(VideoMode(1366, 768), " Game2", Style::Default, settings);
	window.setFramerateLimit(60);

	Image hero_image;
	hero_image.loadFromFile("images/texture.png");
	hero_image.createMaskFromColor(Color(255, 0, 255));
	Texture hero_texture;
	hero_texture.loadFromImage(hero_image);	
	Sprite hero_sprite;
	hero_sprite.setTexture(hero_texture);
	hero_sprite.setTextureRect(IntRect(4, 72, 52, 52));
	hero_sprite.setPosition(100, 100);

	Clock clock;
	float animation_time;

	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			animation_time = clock.getElapsedTime().asSeconds();
			if (animation_time > 0.1)
			{
				hero_sprite.setTextureRect(IntRect(68, 72, 52, 52));
				if (animation_time > 0.2)
				{
					clock.restart();
				}
			} else {
				hero_sprite.setTextureRect(IntRect(4, 72, 52, 52));
			}
			hero_sprite.move(0, -2);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			animation_time = clock.getElapsedTime().asSeconds();
			if (animation_time > 0.1)
			{
				hero_sprite.setTextureRect(IntRect(324, 72, 52, 52));
				if (animation_time > 0.2)
				{
					clock.restart();
				}
			}
			else {
				hero_sprite.setTextureRect(IntRect(260, 72, 52, 52));
			}
			hero_sprite.move(0, 2);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			animation_time = clock.getElapsedTime().asSeconds();
			if (animation_time > 0.1)
			{
				hero_sprite.setTextureRect(IntRect(196, 72, 52, 52));
				if (animation_time > 0.2)
				{
					clock.restart();
				}
			}
			else {
				hero_sprite.setTextureRect(IntRect(132, 72, 52, 52));
			}
			hero_sprite.move(2, 0); 
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			animation_time = clock.getElapsedTime().asSeconds();
			if (animation_time > 0.1)
			{
				hero_sprite.setTextureRect(IntRect(456, 72, 52, 52));
				if (animation_time > 0.2)
				{
					clock.restart();
				}
			}
			else {
				hero_sprite.setTextureRect(IntRect(392, 72, 52, 52));
			}
			hero_sprite.move(-2, 0);
		}

		window.clear();
		window.draw(hero_sprite);
		window.display();
	}
}