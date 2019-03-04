#include "pch.h"
#include "Screen.h"

Screen::Screen(int width, int height, int antialiasingLevel, int framerateLimit, string title)
{
	this->width = width;
	this->height = height;
	this->antialiasingLevel = antialiasingLevel;
	this->framerateLimit = framerateLimit;
	this->title = title;

	ContextSettings settings;
	settings.antialiasingLevel = antialiasingLevel;
	window.create(VideoMode(width, height), title, Style::Default, settings);
	window.setFramerateLimit(framerateLimit);
}