#include "Field.h"



Field::Field()
{
	m_score = 0;
	m_gameOver = false;

	m_font.loadFromFile("font.ttf");

	m_scoreText.setFont(m_font);
	m_scoreText.setString(std::to_string(m_score));
	m_scoreText.setCharacterSize(32);
	m_scoreText.setPosition(5, 5);
	m_scoreText.setColor(sf::Color::Black);

	// Generate every tile on the field
	for (int y = 0; y < TPC; y++)
	{
		for (int x = 0; x < TPR; x++)
		{
			// Magic numbers and hardcoding is completely acceptable
			// Kill me please
			// Errors due to this so far: 4
			Tile t(sf::Vector2f(TILESIZE, TILESIZE));
			t.setFillColor(sf::Color::White);
			t.setPosition(sf::Vector2f(x * TILESIZE, y * TILESIZE));
			m_field.insert(std::pair<Vector2D, Tile>(Vector2D(x, y), t));
		}
	}
	
	// choose a random field and color it red, so it is a fruit field
	range = std::uniform_int_distribution<int>(0, 32);
	engine.seed(time(NULL));
	m_field.find(Vector2D(range(engine), range(engine)))->second.setFillColor(sf::Color::Red);
}


Field::~Field()
{
}

bool Field::IsOnFruit(Vector2D pos)
{
	// if the field at the given position is red, the position is a fruit
	if (m_field.find(pos)->second.getFillColor() == sf::Color::Red)
	{
		// the snake is now on the fruit, so delete the fruit by coloring the tile white
		m_field.find(pos)->second.setFillColor(sf::Color::White);
		// choose another field and make it the fruit
		m_field.find(Vector2D(range(engine), range(engine)))->second.setFillColor(sf::Color::Red);

		//update score
		m_score++;
		m_scoreText.setString(std::to_string(m_score));
		return true;
	}

	return false;
}

void Field::Render(sf::RenderWindow& window)
{
	// render field
	for (auto it : m_field)
		window.draw(it.second);

	// render score
	window.draw(m_scoreText);
}