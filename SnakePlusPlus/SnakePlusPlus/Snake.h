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

	void Render(sf::RenderWindow& window);
	bool Update(Field& field);
	void setDirection(Vector2D dir) { m_direction = dir; }

private:
	std::vector<SnakePiece> m_snake;
	Vector2D m_direction;

	sf::Clock m_clock;
};

