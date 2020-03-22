#ifndef Figure_h
#define Figure_h

#include <map>
#include <list>
#include <SFML/Graphics.hpp>

class Figure
{
public:

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

	Figure(FigureType type, FigureColor color)
	{
		type_ = type;
		color_ = color;
	}

	void setType(FigureType type) { type_ = type; }
	FigureType getType() { return type_; }
	void setColor(FigureColor color) { color_ = color; }
	FigureColor getColor() { return color_; }

private:
	FigureType type_;
	FigureColor color_;
};

#endif // !Figure_h
