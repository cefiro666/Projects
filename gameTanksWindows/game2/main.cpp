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

	Image heroImage;
	heroImage.loadFromFile("images/texture.png");
	heroImage.createMaskFromColor(Color(255, 0, 255));
	Texture heroTexture;
	heroTexture.loadFromImage(heroImage);
	Sprite heroSprite;
	heroSprite.setTexture(heroTexture);
	heroSprite.setTextureRect(IntRect(4, 72, 52, 52));
	heroSprite.setPosition(100, 100);

	Clock clock;
	float animation_time;

	Bullet bul(up, 150, 100);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		
		bul.moveBullet();

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (heroSprite.getPosition().y > 0)
			{
				animation_time = clock.getElapsedTime().asSeconds();
				if (animation_time > 0.1)
				{
					heroSprite.setTextureRect(IntRect(68, 72, 52, 52));
					if (animation_time > 0.2)
					{
						clock.restart();
					}
				} else {
					heroSprite.setTextureRect(IntRect(4, 72, 52, 52));
				}
				heroSprite.move(0, -2);
			}
		} else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (heroSprite.getPosition().y + 52 < 832)
			{
				animation_time = clock.getElapsedTime().asSeconds();
				if (animation_time > 0.1)
				{
					heroSprite.setTextureRect(IntRect(324, 72, 52, 52));
					if (animation_time > 0.2)
					{
						clock.restart();
					}
				} else {
					heroSprite.setTextureRect(IntRect(260, 72, 52, 52));
				}
				heroSprite.move(0, 2);
			}
		} else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (heroSprite.getPosition().x + 52 < 832)
			{
				animation_time = clock.getElapsedTime().asSeconds();
				if (animation_time > 0.1)
				{
					heroSprite.setTextureRect(IntRect(196, 72, 52, 52));
					if (animation_time > 0.2)
					{
						clock.restart();
					}
				} else {
					heroSprite.setTextureRect(IntRect(132, 72, 52, 52));
				}
				heroSprite.move(2, 0);
			}
		} else if (Keyboard::isKeyPressed(Keyboard::Left)) 
		{
			if (heroSprite.getPosition().x > 0)
			{
				animation_time = clock.getElapsedTime().asSeconds();
				if (animation_time > 0.1)
				{
					heroSprite.setTextureRect(IntRect(456, 72, 52, 52));
					if (animation_time > 0.2)
					{
						clock.restart();
					}
				} else {
					heroSprite.setTextureRect(IntRect(392, 72, 52, 52));
				}
				heroSprite.move(-2, 0);
			}
		}

		window.clear();
		window.draw(bul.bulletSprite);
		window.draw(heroSprite);
		window.display();
	}
}