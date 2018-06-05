#pragma once

#include <SFML/Graphics.hpp>

#define WIDTH 825
#define HEIGHT 825
#define TILESIZE 25
#define TPR WIDTH / TILESIZE
#define TPC HEIGHT / TILESIZE

// My own Vector2 class because sf::Vector2f does not have a < operator
struct Vector2D {
	Vector2D(){}
	Vector2D(float x, float y) :
		x(x),
		y(y)
	{}

	float x;
	float y;

	friend bool operator<(const Vector2D& lhs, const Vector2D& rhs)
	{
		if (lhs.y < rhs.y)
			return true;
		else if (lhs.y > rhs.y)
			return false;
		else if (lhs.x < rhs.x)
			return true;
		else
			return false;
	}

	friend bool operator==(const Vector2D& lhs, const Vector2D& rhs)
	{
		if (lhs.x == rhs.x && lhs.y == rhs.y)
			return true;
		
		return false;
	}

	Vector2D& operator=(const Vector2D& rhs)
	{
		x = rhs.x;
		y = rhs.y;

		return *this;
	}

	Vector2D& operator+=(const Vector2D& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	friend Vector2D& operator+(const Vector2D& lhs, const Vector2D& rhs)
	{
		return Vector2D(lhs.x + rhs.x, lhs.y + rhs.y);
	}
};

struct SnakePiece
{
	SnakePiece(Vector2D position)
	{
		this->position = Vector2D(position.x, position.y);

		tile.setSize(sf::Vector2f(TILESIZE, TILESIZE));
		tile.setPosition(TILESIZE * position.x, TILESIZE * position.y); // "I will redo this properly without magic numbers"
																		// i did it!
		tile.setFillColor(sf::Color::Black);
	}

	Vector2D position;
	sf::RectangleShape tile;
};