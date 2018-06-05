#pragma once

#include <map>
#include <random>
#include <SFML/Graphics.hpp>

#include "util.h"

typedef sf::RectangleShape Tile;


class Field
{
public:
	Field();
	~Field();

	/**
		Renders the playfield to the screen

		@param window a reference to the window object
	*/
	void Render(sf::RenderWindow& window);

	/**
		Checks wether the given position is a fruit or not and updates the field accordingly

		@param pos The position to be checked
		@returns wether there is a fruit or not
	*/
	bool IsOnFruit(Vector2D pos);

private:
	std::map<Vector2D, Tile> m_field;	// A map containing every tile

	// RNG
	std::default_random_engine engine;
	std::uniform_int_distribution<int> range;

	unsigned int m_score;
	bool m_gameOver;
	sf::Font m_font;
	sf::Text m_scoreText;
};

