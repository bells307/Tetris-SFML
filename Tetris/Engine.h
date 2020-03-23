#ifndef Director_h
#define Director_h

#include <SFML/Graphics.hpp>
#include "Figure.h"
#include "Constants.h"
#include "TileHelper.h"

// ‘игура - координаты точек фигуры на поле
typedef std::pair<Figure*, std::vector<sf::Vector2f>> FigurePositionPair;

//  ласс, который отвечает за логику игры и отрисовку фигур на поле
class Engine
{
public:
	Engine(sf::RenderWindow* window);

	// ќтрисовать текущее состо€ние игрового пол€
	void drawFigures();
	// ќбработка нажати€ клавиши пользователем
	void keyPressed(sf::Keyboard::Key key);

protected:
	// —оздать фигуру на поле
	void createFigure(Figure::FigureType type, Figure::FigureColor color);
	void createFigure(Figure* figure);
	// ѕереместить фигуру
	void moveFigure(Figure::FigureMoveDirection dir);
	// ѕовернуть фигуру
	void rotateFigure();
	// ѕолучить значени€ закрашенных квадратов из таблицы компоновки дл€ текущей фигуры
	std::vector<int> getRelativeLayoutValues(Figure* figure);

private:
	// ќкно, в котором происходит отрисовка
	sf::RenderWindow* window_ = nullptr;
	TileHelper* tileHelper_ = nullptr;
	// “аймер, по истечению которого фигура сдвигаетс€ на один пункт вниз
	sf::Clock clock_;
	// “екуща€ фигура, над которой происходит работа (может быть только одна!)
	FigurePositionPair currentFigure_;
};

#endif // !Director_h

