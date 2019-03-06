#include "pch.h"
#include "Screen.h"

Screen::Screen(int width, int height, int antialiasingLevel, int framerateLimit, string title)
{
	this->width = width;
	this->height = height;
	settings.antialiasingLevel = antialiasingLevel;
	window.create(VideoMode(this->width, this->height), title, Style::Default, settings);
	window.setFramerateLimit(framerateLimit);
}