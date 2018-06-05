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

	void Render(sf::RenderWindow& window);
	bool IsOnFruit(Vector2D pos);

private:
	std::map<Vector2D, Tile> m_field;
	Vector2D fruitField;

	std::default_random_engine engine;
	std::uniform_int_distribution<int> range;

	unsigned int m_score;
	bool m_gameOver;
	sf::Font m_font;
	sf::Text m_scoreText;
};

