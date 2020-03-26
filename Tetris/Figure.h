#ifndef Figure_h
#define Figure_h

#include <map>
#include <list>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Types.h"

// Класс, описывающий тип и цвет тетрамино
class Figure
{
public:
	// Получить случайную фигуру
	static Figure* getRandomFigure();

	Figure(FigureType type, FigureColor color);

	void setType(FigureType type) { type_ = type; }
	FigureType getType() { return type_; }
	void setColor(FigureColor color) { color_ = color; }
	FigureColor getColor() { return color_; }


private:
	FigureType type_;
	FigureColor color_;
};

#endif // !Figure_h
