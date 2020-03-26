#pragma once

#include "Figure.h"
#include <map>
#include <vector>

namespace constants
{
	// Путь к файлу с тайлами
	const std::string TileTextureFileName = "D:\\dev\\repos\\C++\\Tetris-SFML\\x64\\Debug\\images\\tiles.png";

	// Размер тайла
	const int TileSide = 18;

	// Высота поля
	const int FieldHeight = 20;
	// Ширина поля
	const int FieldWidth = 10;

	// Таблица компоновки фигур
	const std::map<FigureType, std::vector<int>> RelativeLayoutTableValues
	{
		{ FigureType::S, { 2, 4, 5, 7 } },
		{ FigureType::I, { 1, 3, 5, 7 } },
		{ FigureType::Z, { 3, 5, 4, 6 } },
		{ FigureType::T, { 3, 5, 4, 7 } },
		{ FigureType::L, { 2, 3, 5, 7 } },
		{ FigureType::J, { 3, 5, 7, 6 } },
		{ FigureType::O, { 2, 3, 4, 5 } },
	};

	// Задержка таймера, по истечению которой фигура сдвигается вниз
	const float TimerDelay = 0.3;
}
