#ifndef Engine_h
#define Engine_h

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Types.h"
#include "Figure.h"
#include "Field.h"

// �����, ������� �������� �� ������ ���� � ��������� ����� �� ����
class Engine
{
public:
	Engine(sf::RenderWindow* window);
	~Engine();

	// ���������� ������� ��������� �������� ����
	void drawFigures();
	// ��������� ������� ������� �������������
	void keyPressed(sf::Keyboard::Key key);

protected:
	// ������� ������ �� ����
	void createFigure(FigureType type, FigureColor color);
	void createFigure(Figure* figure);
	void setTilePositions(TilePositionsMap& newTilePositions);
	// ����������� ������
	void moveCurrentFigure(FigureMoveDirection dir);
	// ��������� ������
	void rotateCurrentFigure();
	// �������� �������� ����������� ��������� �� ������� ���������� ��� ������� ������
	std::vector<int> getRelativeLayoutValues(Figure* figure);

	Field* getField() { return field_; }
	Figure* getCurrentFigure() { return currentFigure_.first; }
	void setCurrentFigure(Figure* figure, TilePositionsMap tilePositions) { currentFigure_ = std::make_pair(figure, tilePositions); }
	TilePositionsMap& getCurrentFigureTilePositions() { return currentFigure_.second; }
	sf::RenderWindow* getWindow() { return window_; }

private:
	// ����, � ������� ���������� ���������
	sf::RenderWindow* window_ = nullptr;
	Field* field_ = nullptr;
	// ������, �� ��������� �������� ������ ���������� �� ���� ����� ����
	sf::Clock clock_;
	// ������� ������, ��� ������� ���������� ������ (����� ���� ������ ����!)
	FigurePositionPair currentFigure_;
};

#endif // !Engine_h

