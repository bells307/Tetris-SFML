#include <SFML/Graphics.hpp>
#include "Constants.h"

using namespace sf;

struct Point
{
	int x, y;
} a[4], b[4];

int main()
{
	RenderWindow window(VideoMode(320, 480), "Game");

	// Загружаем текстуру из файла
	Texture texture;
	texture.loadFromFile("C:\\dev\\C++\\SFML_test_proj\\x64\\Debug\\images\\tiles.png");

	Sprite sprite(texture);
	sprite.setTextureRect(IntRect(0, 0, 18, 18));

	// Смещение по горизонтали
	int dx = 0;
	bool rotate = false;

	float timer = 0, delay = 0.3;

	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
					dx = -1;
				else if (event.key.code == Keyboard::Right)
					dx = 1;
				else if (event.key.code == Keyboard::Up)
					rotate = true;
			}
		}

		window.clear(Color::White);

		int n = 3;

		if (a[0].x == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				a[i].x = Figures[n][i] % 2;
				a[i].y = Figures[n][i] / 2;
			}
		}

		for (int i = 0; i < 4; i++)
			a[i].x += dx;

		if (rotate)
		{
			Point p = a[1];

			for (int i = 0; i < 4; i++)
			{
				int x = a[i].y - p.y; // y - y0
				int y = a[i].x - p.x; // x - x0
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			sprite.setPosition(a[i].x * 18, a[i].y * 18);
			window.draw(sprite);
		}

		if (timer > delay)
		{
			for (int i = 0; i < 4; i++)
				a[i].y++;

			timer = 0;
		}

		dx = 0;
		rotate = false;

		window.display();
	}
}