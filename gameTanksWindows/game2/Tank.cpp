#include "pch.h"
#include "Tank.h"


Tank::Tank()
{
	tankImage.loadFromFile("images/texture.png");
	tankImage.createMaskFromColor(Color(255, 0, 255));
	tankTexture.loadFromImage(tankImage);
	tankSprite.setTexture(tankTexture);
	tankSprite.setTextureRect(IntRect(4, 72, 52, 52));
	tankSprite.setPosition(100, 100);
};

void Tank::moveTank()
{
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		if (tankSprite.getPosition().y > 0) {
			animation_time = clock.getElapsedTime().asSeconds();
			if (animation_time > 0.1) {
				tankSprite.setTextureRect(IntRect(68, 72, 52, 52));
				if (animation_time > 0.2) {
					clock.restart();
				}
			} else {
				tankSprite.setTextureRect(IntRect(4, 72, 52, 52));
			}
			tankSprite.move(0, -2);
		}
	} else if (Keyboard::isKeyPressed(Keyboard::Down)) {
		if (tankSprite.getPosition().y + 52 < 832) {
			animation_time = clock.getElapsedTime().asSeconds();
			if (animation_time > 0.1) {
				tankSprite.setTextureRect(IntRect(324, 72, 52, 52));
				if (animation_time > 0.2) {
					clock.restart();
				}
			} else {
				tankSprite.setTextureRect(IntRect(260, 72, 52, 52));
			}
			tankSprite.move(0, 2);
		}
	} else if (Keyboard::isKeyPressed(Keyboard::Right)) {
		if (tankSprite.getPosition().x + 52 < 832) {
			animation_time = clock.getElapsedTime().asSeconds();
			if (animation_time > 0.1) {
				tankSprite.setTextureRect(IntRect(196, 72, 52, 52));
				if (animation_time > 0.2) {
					clock.restart();
				}
			} else {
				tankSprite.setTextureRect(IntRect(132, 72, 52, 52));
			}
			tankSprite.move(2, 0);
		}
	} else if (Keyboard::isKeyPressed(Keyboard::Left)) {
		if (tankSprite.getPosition().x > 0) {
			animation_time = clock.getElapsedTime().asSeconds();
			if (animation_time > 0.1) {
				tankSprite.setTextureRect(IntRect(456, 72, 52, 52));
				if (animation_time > 0.2) {
					clock.restart();
				}
			} else {
				tankSprite.setTextureRect(IntRect(392, 72, 52, 52));
			}
			tankSprite.move(-2, 0);
		}
	}
}

Tank::~Tank()
{
}
