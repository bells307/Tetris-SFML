#ifndef Figure_h
#define Figure_h

#include <map>
#include <list>
#include <SFML/Graphics.hpp>
#include <time.h>

// Класс, описывающий тип и цвет тетрамино
class Figure
{
public:

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

	Figure(FigureType type, FigureColor color)
	{
		type_ = type;
		color_ = color;
	}

	void setType(FigureType type) { type_ = type; }
	FigureType getType() { return type_; }
	void setColor(FigureColor color) { color_ = color; }
	FigureColor getColor() { return color_; }

	// Получить случайную фигуру
	static Figure* getRandomFigure()
	{
		srand(time(0));
		FigureType type = (FigureType)(rand() % FigureType::TypeCount - 1);
		FigureColor color = (FigureColor)(rand() % FigureColor::ColorCount - 1);

		return new Figure(type, color);
	}

private:
	FigureType type_;
	FigureColor color_;
};

#endif // !Figure_h
