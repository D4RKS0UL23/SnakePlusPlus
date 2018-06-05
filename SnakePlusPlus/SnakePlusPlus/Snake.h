#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "util.h"
#include "Field.h"

typedef sf::RectangleShape Tile;

class Snake
{
public:
	Snake();
	virtual ~Snake();

	/**
		Renders all Tiles of the snake

		@param window Adress of the window object
	*/
	void Render(sf::RenderWindow& window);

	/**
		Updates the snake by moving every tile to it's new position

		@param field an adress to the field object
		@return Returns false when the Snake crashes into the wall or itself
	*/
	bool Update(Field& field);

	/**
		Sets the new direction the snake is going

		@param dir the new direction
	*/
	void setDirection(Vector2D dir) { m_direction = dir; }

private:
	std::vector<SnakePiece> m_snake;
	Vector2D m_direction;

	sf::Clock m_clock;
};

