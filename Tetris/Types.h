#ifndef Types_h
#define Types_h

#include <SFML/Graphics.hpp>

class Figure;

// Координаты тайла на поле
typedef sf::Vector2i TilePosition;
// Координаты тайлов на поле для фигуры
typedef std::vector<TilePosition> TilePositionsMap;
// Текущая фигура - координаты её тайлов на поле
typedef std::pair<Figure*, TilePositionsMap> FigurePositionPair;

// Тип фигуры
enum FigureType
{
	I,
	S,
	Z,
	T,
	L,
	J,
	O,
	TypeCount
};

// Цвет фигуры
enum FigureColor
{
	NoColor,
	Blue,
	Purple,
	Red,
	Green,
	Yellow,
	Cyan,
	Orange,
	ColorCount
};

// Направления, в которых фигура может двигаться
enum FigureMoveDirection
{
	Left,
	Right,
	Down
};

#endif // !Types_h
