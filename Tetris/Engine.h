#ifndef Director_h
#define Director_h

#include <SFML/Graphics.hpp>
#include "Figure.h"
#include "Constants.h"
#include "TileHelper.h"

// ������ - ���������� ����� ������ �� ����
typedef std::pair<Figure*, std::vector<sf::Vector2f>> FigurePositionPair;

// �����, ������� �������� �� ������ ���� � ��������� ����� �� ����
class Engine
{
public:
	Engine(sf::RenderWindow* window);

	// ���������� ������� ��������� �������� ����
	void drawFigures();
	// ��������� ������� ������� �������������
	void keyPressed(sf::Keyboard::Key key);

protected:
	// ������� ������ �� ����
	void createFigure(Figure::FigureType type, Figure::FigureColor color);
	void createFigure(Figure* figure);
	// ����������� ������
	void moveFigure(Figure::FigureMoveDirection dir);
	// ��������� ������
	void rotateFigure();
	// �������� �������� ����������� ��������� �� ������� ���������� ��� ������� ������
	std::vector<int> getRelativeLayoutValues(Figure* figure);

private:
	// ����, � ������� ���������� ���������
	sf::RenderWindow* window_ = nullptr;
	TileHelper* tileHelper_ = nullptr;
	// ������, �� ��������� �������� ������ ���������� �� ���� ����� ����
	sf::Clock clock_;
	// ������� ������, ��� ������� ���������� ������ (����� ���� ������ ����!)
	FigurePositionPair currentFigure_;
};

#endif // !Director_h

