#include "Framework.h"
#include <iostream>

sf::RenderWindow*	Framework::window = nullptr; //Set Window object to nullptr. If window is nullptr, the framework was not initialized.
sf::Event			Framework::e = sf::Event();		
sf::Clock			Framework::c = sf::Clock();
sf::Font			Framework::m_font = sf::Font();
sf::Text			Framework::m_gameOverText = sf::Text();
sf::Text			Framework::m_FPS = sf::Text();

Field				Framework::m_field = Field();
Snake				Framework::m_snake = Snake();

bool				Framework::m_gameOver = false;	// When the game starts, the game is not over
bool				Framework::m_showFrametime = true;
double				Framework::m_frametime = 0;


Framework::~Framework()
{
	// delete widnow and release memory
	delete window;
	window = nullptr;
}

ErrorType Framework::Initialize(unsigned int width, unsigned int height, std::string title, sf::Uint8 flags)
{
	// If the window is already initialized, then don't initialize it again
	if (window != nullptr)
	{
		std::cout << "WARNING: Framework has already been initialized." << std::endl;
		return WARNING;
	}

	// Set window properties
	window = new sf::RenderWindow(sf::VideoMode(width, height), title, flags);
	window->setFramerateLimit(-1);
	window->setVerticalSyncEnabled(false);

	//Load Font and create GameOver text
	m_font.loadFromFile("font.ttf");

	m_gameOverText.setFont(m_font);
	m_gameOverText.setString("Game\nOver");
	m_gameOverText.setCharacterSize(140);
	m_gameOverText.setPosition(100, 200);
	m_gameOverText.setColor(sf::Color(0, 0, 110));

	m_FPS.setFont(m_font);
	m_FPS.setString(std::to_string(std::floor(1 / m_frametime)));
	m_FPS.setCharacterSize(32);
	m_FPS.setPosition(5, 40);
	m_FPS.setColor(sf::Color(0, 0, 0));

	c.restart();

	return NONE;
}

ErrorType Framework::Run()
{
	// If widnow was not initialized, return error
	if (window == nullptr)
	{
		std::cout << "ERROR: Framework cannot run before being initialized" << std::endl;
		return ERROR;
	}

	//Program loop!
	while (window->isOpen())
	{
		if (Handle() == ERROR) return ERROR;
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
			// When window gets closed
		case sf::Event::Closed:
			window->close();
			break;

			// When a key gets pressed
			// Only used to update the snakes direction
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				m_showFrametime = !m_showFrametime;
			}
		}
	}

	return NONE;
}

ErrorType Framework::Update()
{
	// If the snake's update returns false, it crashed
	// The game is over
	if(!m_gameOver)
		if (!m_snake.Update(m_field))
			m_gameOver = true;

	m_FPS.setString(std::to_string((int)(1 / m_frametime)));
	m_frametime = c.getElapsedTime().asSeconds();
	c.restart();

	return NONE;
}

ErrorType Framework::Render()
{
	// Clear screen
	window->clear(sf::Color::Black);

	// Render the field and the snake
	m_field.Render(*window);
	m_snake.Render(*window);
	
	// If the game is over, display the Game Over Text
	if (m_gameOver)
		window->draw(m_gameOverText);

	if(m_showFrametime)
		window->draw(m_FPS);

	// Display everything to the screen
	window->display();

	return NONE;
}