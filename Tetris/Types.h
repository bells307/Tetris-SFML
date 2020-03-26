#ifndef Types_h
#define Types_h

#include <SFML/Graphics.hpp>

class Figure;

// ���������� ����� �� ����
typedef sf::Vector2i TilePosition;
// ���������� ������ �� ���� ��� ������
typedef std::vector<TilePosition> TilePositionsMap;
// ������� ������ - ���������� � ������ �� ����
typedef std::pair<Figure*, TilePositionsMap> FigurePositionPair;

// ��� ������
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

// ���� ������
enum FigureColor
{
	NoColor,
	Blue,
	Purple,
	Red,
	Green,
	Yellow,
	Cyan,
	Orange,
	ColorCount
};

// �����������, � ������� ������ ����� ���������
enum FigureMoveDirection
{
	Left,
	Right,
	Down
};

#endif // !Types_h
