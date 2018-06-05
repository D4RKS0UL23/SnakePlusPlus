#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Snake.h"

enum ErrorType {
	NONE,
	WARNING,
	ERROR
};

class Framework
{
public:
	virtual ~Framework();

	static ErrorType Initialize(unsigned int width, unsigned int height, std::string title, sf::Uint8 flags = sf::Style::Default);
	static ErrorType Run();

private:
	static ErrorType Handle();
	static ErrorType Update();
	static ErrorType Render();

	static sf::RenderWindow* window;
	static sf::Event e;

	static Field m_field;
	static Snake m_snake;

	static sf::Font m_font;
	static sf::Text m_gameOverText;

	static bool m_gameOver;
};

