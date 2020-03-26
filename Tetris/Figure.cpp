#include "Figure.h"

Figure* Figure::getRandomFigure()
{
	::srand(time(0));
	FigureType type = (FigureType)(::rand() % FigureType::TypeCount - 1);
	FigureColor color = (FigureColor)(1 + ::rand() % FigureColor::ColorCount - 1);

	return new Figure(type, color);
}

Figure::Figure(FigureType type, FigureColor color) :
	type_(type),
	color_(color)
{
}
