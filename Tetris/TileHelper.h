#ifndef TileHelper_h
#define TileHelper_h

#include "Constants.h"
#include "Types.h"

// Цвет фигуры - её спрайт
typedef std::map<FigureColor, sf::Sprite*> FigureSpritesMap;

// Класс для работы с тайлами
class TileHelper
{
public:
	~TileHelper();

	static TileHelper* getInstance();

	// Создать спрайты из тайлов для каждого цвета фигур
	void makeTileSprites(const sf::Texture& texture);
	// Получить спрайт
	sf::Sprite* getTileSprite(FigureColor color);
	sf::Sprite* getTileSprite(Figure* figure);

private:
	TileHelper();

private:
	static TileHelper* instance_;
	FigureSpritesMap tileSprites_;
};

#endif // !TileHelper_h
