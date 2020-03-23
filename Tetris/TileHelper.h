#ifndef TileHelper_h
#define TileHelper_h

#include "Constants.h"

// Цвет фигуры - её спрайт
typedef std::map<Figure::FigureColor, sf::Sprite> FigureSpritesMap;

// Класс для работы с тайлами
class TileHelper
{
public:
	// Создать спрайты из тайлов для каждого цвета фигур
	void makeTileSprites(const sf::Texture& texture)
	{
		tileSprites.clear();
		for (int i = 0, img_count = 0; i < Figure::FigureColor::ColorCount; ++i, img_count += constants::TileSide)
		{
			sf::Sprite sprite(texture);
			sprite.setTextureRect(sf::IntRect(img_count, 0, constants::TileSide, constants::TileSide));
			tileSprites.emplace((Figure::FigureColor)i, sprite);
		}
	}

	// Получить спрайт для фигуры
	sf::Sprite getTileSprite(Figure* figure)
	{
		if (nullptr == figure)
			return sf::Sprite();

		sf::Sprite res;

		auto sprite_it = tileSprites.find(figure->getColor());
		if (sprite_it == tileSprites.end())
			res = sf::Sprite();
		else
			res = (*sprite_it).second;

		return res;
	}

private:
	FigureSpritesMap tileSprites;
};

#endif // !TileHelper_h
