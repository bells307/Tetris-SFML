#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Director.h"
#include "Field.h"

int main()
{
	// Загружаем текстуру из файла
	sf::Texture texture;
	texture.loadFromFile(constants::TextureFileName);

	Director::makeTileSprites(texture);

	sf::RenderWindow window(sf::VideoMode(320, 480), "Game");

	Director director(&window);

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
				director.keyPressed(event.key.code);
			}
		}

		window.clear(sf::Color::White);

		director.drawFigures();

		window.display();
	}
}
