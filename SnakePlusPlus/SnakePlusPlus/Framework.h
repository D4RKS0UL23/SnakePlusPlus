#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Snake.h"

// ErrorType, used to differentiate different Problems in the Program
enum ErrorType {
	NONE,
	WARNING,
	ERROR
};

//Framework: Contains GameLoop, Rendering Routines etc

class Framework
{
public:
	virtual ~Framework();

	/**
		Initializes the Framework

		@param width The width of the window
		@param height The height of the window
		@param title The title of the window
		@param flags The style of the window
		@return ErrorType
	*/
	static ErrorType Initialize(unsigned int width, unsigned int height, std::string title, sf::Uint8 flags = sf::Style::Default);

	/**
		Contains the GameLoop

		@return ErrorType
	*/
	static ErrorType Run();

private:
	/**
		Handles different Events, e.g. closing the Window or KeyStrokes

		@return ErrorType
	*/
	static ErrorType Handle();

	/**
		Updates the different parts of the program

		@return ErrorType
	*/
	static ErrorType Update();

	/**
		Renders all parts of the program that

		@return ErrorType
	*/
	static ErrorType Render();

	
	static sf::RenderWindow* window;	//	The window object
	static sf::Event e;					//	An event holder, which saves current events
	static sf::Clock c;

	static Field m_field;				// The gamefield (The Field is a grid of white tiles)
	static Snake m_snake;				// The snake (a collection of black tiles)

	static sf::Font m_font;				// Font Holder
	static sf::Text m_gameOverText;		// GameOver Text
	static sf::Text m_FPS;

	static bool m_gameOver;
	static double m_frametime;
	static bool m_showFrametime;

};

