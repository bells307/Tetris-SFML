#ifndef Figure_h
#define Figure_h

#include <map>
#include <list>
#include <SFML/Graphics.hpp>
#include "Constants.h"

enum FigureType
{
	I,
	S,
	Z,
	T,
	L,
	J,
	O
};

enum FigureColor
{
	Blue,
	Purple,
	Red,
	Green,
	Yellow,
	Cyan,
	Orange,
	Count
};

enum FigureMoveDirection
{
	Left,
	Right,
	Down
};

const std::map<FigureType, std::vector<int>> FigureValues
{
	{ FigureType::I, { 1, 3, 5, 7 } },
	{ FigureType::S, { 2, 4, 5, 7 } },
	{ FigureType::Z, { 3, 5, 4, 6 } },
	{ FigureType::T, { 3, 5, 4, 7 } },
	{ FigureType::L, { 2, 3, 5, 7 } },
	{ FigureType::J, { 3, 5, 7, 6 } },
	{ FigureType::O, { 2, 3, 4, 5 } },
};

class Figure
{
public:
	Figure(FigureType type, FigureColor color);

	std::vector<int> getFigureValues();

	void setType(FigureType type) { type_ = type; }
	FigureType getType() { return type_; }
	void setColor(FigureColor color) { color_ = color; }
	FigureColor getColor() { return color_; }

private:
	FigureType type_;
	FigureColor color_;
};

#endif // !Figure_h
