#include "Snake.h"

#include <iostream>

Snake::Snake()
{
	//Create three initial Snake Pieces in the same spot
	for (int i = 0; i < 3; i++)
	{
		m_snake.push_back(SnakePiece(Vector2D(16, 16)));
	}

	m_direction = Vector2D(1, 0);	// Standard direction is right
	m_clock.restart();				// Restart the Snake's clock
}


Snake::~Snake()
{
}

bool Snake::Update(Field& field)
{
	// The snake gets updated every second
	if (m_clock.getElapsedTime().asMilliseconds() >= 250)
	{
		//remove the last tile in the vector, which thereby is the last piece of the snake
		m_snake.pop_back();

		// Create a new snake piece in front of the frontmost piece and insert it at the beginning of the vector
		Vector2D v = m_snake.begin()->position + m_direction;
		m_snake.insert(m_snake.begin(), v);

		// If the snake's 'head' is out of bounds, it crashed -> Game Over
		if (m_snake.begin()->position.x > 32 ||
			m_snake.begin()->position.x < 0 ||
			m_snake.begin()->position.y > 32 ||
			m_snake.begin()->position.y < 0)
		{
			return false;
		}

		// If the snake crashes into itself -> Game over
		auto it = m_snake.begin();
		it++;

		while (it != m_snake.end())
		{
			// if the snakes head's position equals another part's position, it crashed into itself
			if (m_snake.begin()->position == it->position)
				return false;
			it++;
		}

		// Checks wether the snake ate a fruit or not
		if (field.IsOnFruit(m_snake.begin()->position))
		{
			// if yes, create a new tile on top of the last tile
			m_snake.insert(m_snake.end(), m_snake.back());
		}

		// restart the clock
		m_clock.restart();
	}

	return true;
}

void Snake::Render(sf::RenderWindow& window)
{
	// render the snake
	for (auto it : m_snake)
	{
		window.draw(it.tile);
	}
}