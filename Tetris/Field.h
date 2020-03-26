#ifndef Field_h
#define Field_h

#include <array>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Types.h"

struct FieldPoint
{
	FigureColor color = FigureColor::NoColor;
};

typedef std::array<std::array<FieldPoint, constants::FieldHeight>, constants::FieldWidth> FieldPointsArray;

class Field
{
public:
	FieldPointsArray& getFieldPoints() { return fieldPoints_; }

private:
	FieldPointsArray fieldPoints_;
};

#endif // !Field_h

