#pragma once

#include "Figure.h"
#include <map>
#include <list>

namespace constants
{
	// Путь к файлу с тайлами
	
	const std::string TileTextureFileName = "C:\\dev\\C++\\Tetris\\x64\\Debug\\images\\tiles.png";

	// Размер тайла
	const int TileSide = 18;

	// Высота поля
	const int FieldHeight = 20;
	// Ширина поля
	const int FieldWeight = 10;

	// Таблица компоновки фигур
	const std::map<Figure::FigureType, std::vector<int>> RelativeLayoutTableValues
	{
		{ Figure::FigureType::I, { 1, 3, 5, 7 } },
		{ Figure::FigureType::S, { 2, 4, 5, 7 } },
		{ Figure::FigureType::Z, { 3, 5, 4, 6 } },
		{ Figure::FigureType::T, { 3, 5, 4, 7 } },
		{ Figure::FigureType::L, { 2, 3, 5, 7 } },
		{ Figure::FigureType::J, { 3, 5, 7, 6 } },
		{ Figure::FigureType::O, { 2, 3, 4, 5 } },
	};

	// Задержка таймера, по истечению которой фигура сдвигается вниз
	const float TimerDelay = 0.3;
}
