#include "Framework.h"
#include <iostream>

sf::RenderWindow*	Framework::window = nullptr; //Set Window object to nullptr. If window is nullptr, the framework was not initialized.
sf::Event			Framework::e = sf::Event();
sf::Font			Framework::m_font = sf::Font();
sf::Text			Framework::m_gameOverText = sf::Text();

Field				Framework::m_field = Field();
Snake				Framework::m_snake = Snake();

bool				Framework::m_gameOver = false;


Framework::~Framework()
{
	delete window;
	window = nullptr;
}

ErrorType Framework::Initialize(unsigned int width, unsigned int height, std::string title, sf::Uint8 flags)
{
	if (window != nullptr)
	{
		std::cout << "WARNING: Framework has already been initialized." << std::endl;
		return WARNING;
	}

	window = new sf::RenderWindow(sf::VideoMode(width, height), title, flags);

	m_font.loadFromFile("font.ttf");
	m_gameOverText.setFont(m_font);
	m_gameOverText.setString("Game\nOver");
	m_gameOverText.setCharacterSize(140);
	m_gameOverText.setPosition(100, 200);
	m_gameOverText.setColor(sf::Color::Black);
	return NONE;
}

ErrorType Framework::Run()
{
	if (window == nullptr)
	{
		std::cout << "ERROR: Framework cannot run before being initialized" << std::endl;
		return ERROR;
	}

	while (window->isOpen())
	{
		if (Handle() == ERROR) return ERROR;
		if(!m_gameOver)
			if (Update() == ERROR) return ERROR;
		if (Render() == ERROR) return ERROR;
	}

	return NONE;
}

ErrorType Framework::Handle()
{
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				m_snake.setDirection(Vector2D(0, -1));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				m_snake.setDirection(Vector2D(-1, 0));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				m_snake.setDirection(Vector2D(0, 1));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				m_snake.setDirection(Vector2D(1, 0));
			}
		}
	}

	return NONE;
}

ErrorType Framework::Update()
{
	if (!m_snake.Update(m_field))
		m_gameOver = true;

	return NONE;
}

ErrorType Framework::Render()
{
	window->clear(sf::Color::Black);

	m_field.Render(*window);
	m_snake.Render(*window);

	if (m_gameOver)
		window->draw(m_gameOverText);

	window->display();
	return NONE;
}