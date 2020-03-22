#pragma once

#include "Figure.h"
#include <map>
#include <list>

namespace constants
{
	const std::string TextureFileName = "C:\\dev\\C++\\Tetris\\x64\\Debug\\images\\tiles.png";

	const int TileSide = 18;

	const int FieldHeight = 20;
	const int FieldWeight = 10;

	const std::map<Figure::FigureType, std::vector<int>> FigureValues
	{
		{ Figure::FigureType::I, { 1, 3, 5, 7 } },
		{ Figure::FigureType::S, { 2, 4, 5, 7 } },
		{ Figure::FigureType::Z, { 3, 5, 4, 6 } },
		{ Figure::FigureType::T, { 3, 5, 4, 7 } },
		{ Figure::FigureType::L, { 2, 3, 5, 7 } },
		{ Figure::FigureType::J, { 3, 5, 7, 6 } },
		{ Figure::FigureType::O, { 2, 3, 4, 5 } },
	};

	const float TimerDelay = 0.3;
}
