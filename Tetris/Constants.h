#pragma once

#include "Figure.h"
#include <map>
#include <vector>

namespace constants
{
	// ���� � ����� � �������
	const std::string TileTextureFileName = "D:\\dev\\repos\\C++\\Tetris-SFML\\x64\\Debug\\images\\tiles.png";

	// ������ �����
	const int TileSide = 18;

	// ������ ����
	const int FieldHeight = 20;
	// ������ ����
	const int FieldWidth = 10;

	// ������� ���������� �����
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

	// �������� �������, �� ��������� ������� ������ ���������� ����
	const float TimerDelay = 0.3;
}
