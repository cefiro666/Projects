#include "pch.h"
#include "Screen.h"
#include "Ball.h"
#include "Player.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{	
	Screen screen(1000, 600, 4, 60, "Pong");
	Player left(15, 80, 50, 200, Color::Green, 250, 50);
	Player right(15, 80, 935, 200, Color::Blue, 720, 50);
	Ball ball(10, 500, 300, Color::Red);
	Clock timer;

	while (screen.window.isOpen())
	{

		left.string_score = to_string(left.score);
		left.text_score.setString(left.string_score);

		right.string_score = to_string(right.score);
		right.text_score.setString(right.string_score);

		Event event;
		while (screen.window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				screen.window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) 
		{
			left.up(10);
		}

		if (Keyboard::isKeyPressed(Keyboard::S)) 
		{
			left.down(10);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) 
		{
			right.up(10);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) 
		{
			right.down(10);
		}

		Time time = timer.getElapsedTime();
		float pause = time.asSeconds();
		
		if (pause > 2) 
		{
			ball.start = true;
			timer.restart();
		}

		if (ball.start) {
			ball.x_offset(10, left, right);
			ball.y_offset(5);
		}
		cout << ball.false_repulse << endl;
		screen.window.clear();
		screen.window.draw(left.platform);
		screen.window.draw(left.text_score);
		screen.window.draw(right.platform);
		screen.window.draw(right.text_score);
		screen.window.draw(ball.circle);
		screen.window.display();
	}
}
