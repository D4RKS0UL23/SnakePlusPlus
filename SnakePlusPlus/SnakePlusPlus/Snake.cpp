#include "Snake.h"

#include <iostream>

Snake::Snake()
{
	for (int i = 0; i < 3; i++)
	{
		m_snake.push_back(SnakePiece(Vector2D(16, 16)));
	}

	m_direction = Vector2D(1, 0);
	m_clock.restart();
}


Snake::~Snake()
{
}

bool Snake::Update(Field& field)
{
	if (m_clock.getElapsedTime().asMilliseconds() >= 250)
	{
		m_snake.pop_back();

		Vector2D v = m_snake.begin()->position + m_direction;
		m_snake.insert(m_snake.begin(), v);

		if (m_snake.begin()->position.x > 32 ||
			m_snake.begin()->position.x < 0 ||
			m_snake.begin()->position.y > 32 ||
			m_snake.begin()->position.y < 0)
		{
			return false;
		}

		auto it = m_snake.begin();
		it++;

		while (it != m_snake.end())
		{
			if (m_snake.begin()->position == it->position)
				return false;
			it++;
		}

		if (field.IsOnFruit(m_snake.begin()->position))
		{
			std::cout << "Score!" << std::endl;
			m_snake.insert(m_snake.end(), m_snake.back());
		}

		m_clock.restart();
	}

	return true;
}

void Snake::Render(sf::RenderWindow& window)
{
	for (auto it : m_snake)
	{
		window.draw(it.tile);
	}
}