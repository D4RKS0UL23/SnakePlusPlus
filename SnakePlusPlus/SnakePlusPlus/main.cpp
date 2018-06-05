#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 800), "SnakePlusPlus v1.0", sf::Style::None | sf::Style::Close);
	sf::Event e;

	while (window->isOpen())
	{
		while (window->pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window->close();
			}
		}

		window->clear();

		window->display();
	}
}