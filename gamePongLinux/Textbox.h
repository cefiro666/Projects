#pragma once

//класс текстовых блоков
class Textbox 
{
private:
	Text text;
	Font font;

public:
	Textbox(int size, float x, float y, string content)
	{
		font.loadFromFile("fonts/LCDM2B__.TTF");
		text.setFont(font);
		text.setCharacterSize(size);
		text.setFillColor(Color(255, 255, 255, 200));
		text.setPosition(x, y);
		text.setString(content);
	}
	friend int main();
};