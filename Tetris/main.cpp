#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Engine.h"
#include "Field.h"
#include "TileHelper.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(320, 480), "Game");

	Engine engine(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				engine.keyPressed(event.key.code);
			}
		}

		window.clear(sf::Color::White);

		engine.drawFigures();

		window.display();
	}
}
