#ifndef Director_h
#define Director_h

#include <SFML/Graphics.hpp>
#include "Figure.h"
#include "Constants.h"

typedef std::map<FigureColor, sf::Sprite> FigureSpritesMap;
typedef std::pair<Figure*, std::vector<sf::Vector2f>> FigurePositionPair;
static FigureSpritesMap tileSprites;

class Director
{
public:
	Director(sf::RenderWindow* window);

	void drawFigures();
	void keyPressed(sf::Keyboard::Key key);

	static void makeTileSprites(const sf::Texture& texture);
	static sf::Sprite getTileSprite(Figure* figure);

protected:
	void createFigure(FigureType type, FigureColor color);
	void moveFigure(FigureMoveDirection dir);
	void rotateFigure();

private:
	sf::RenderWindow* window_ = nullptr;
	FigurePositionPair currentFigure_;
	std::vector<FigurePositionPair> figuresVector;
};

#endif // !Director_h

