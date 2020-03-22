#include "Figure.h"
#include "Director.h"

Figure::Figure(FigureType type, FigureColor color) :
	type_(type),
	color_(color)
{
}

std::vector<int> Figure::getFigureValues()
{
	std::vector<int> res;
	auto find_it = FigureValues.find(type_);
	if (find_it != FigureValues.end())
		res = (*find_it).second;

	return res;
}