#ifndef Engine_h
#define Engine_h

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Types.h"
#include "Figure.h"
#include "Field.h"

//  ласс, который отвечает за логику игры и отрисовку фигур на поле
class Engine
{
public:
	Engine(sf::RenderWindow* window);
	~Engine();

	// ќтрисовать текущее состо€ние игрового пол€
	void drawFigures();
	// ќбработка нажати€ клавиши пользователем
	void keyPressed(sf::Keyboard::Key key);

protected:
	// —оздать фигуру на поле
	void createFigure(FigureType type, FigureColor color);
	void createFigure(Figure* figure);
	void setTilePositions(TilePositionsMap& newTilePositions);
	// ѕереместить фигуру
	void moveCurrentFigure(FigureMoveDirection dir);
	// ѕовернуть фигуру
	void rotateCurrentFigure();
	// ѕолучить значени€ закрашенных квадратов из таблицы компоновки дл€ текущей фигуры
	std::vector<int> getRelativeLayoutValues(Figure* figure);

	Field* getField() { return field_; }
	Figure* getCurrentFigure() { return currentFigure_.first; }
	void setCurrentFigure(Figure* figure, TilePositionsMap tilePositions) { currentFigure_ = std::make_pair(figure, tilePositions); }
	TilePositionsMap& getCurrentFigureTilePositions() { return currentFigure_.second; }
	sf::RenderWindow* getWindow() { return window_; }

private:
	// ќкно, в котором происходит отрисовка
	sf::RenderWindow* window_ = nullptr;
	Field* field_ = nullptr;
	// “аймер, по истечению которого фигура сдвигаетс€ на один пункт вниз
	sf::Clock clock_;
	// “екуща€ фигура, над которой происходит работа (может быть только одна!)
	FigurePositionPair currentFigure_;
};

#endif // !Engine_h

