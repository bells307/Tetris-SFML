#include "Engine.h"

Engine::Engine(sf::RenderWindow* window) :
	window_(window)
{
	tileHelper_ = new TileHelper();

	// “екстура тайла
	sf::Texture* tileTexture = new sf::Texture();
	tileTexture->loadFromFile(constants::TileTextureFileName);

	tileHelper_->makeTileSprites(*tileTexture);

	createFigure(Figure::getRandomFigure());
}

void Engine::keyPressed(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Left:
		moveFigure(Figure::FigureMoveDirection::Left);
		break;
	case sf::Keyboard::Right:
		moveFigure(Figure::FigureMoveDirection::Right);
		break;
	case sf::Keyboard::Down:
		moveFigure(Figure::FigureMoveDirection::Down);
		break;
	case sf::Keyboard::Up:
		rotateFigure();
		break;
	default:
		break;
	}
}

void Engine::createFigure(Figure::FigureType type, Figure::FigureColor color)
{
	createFigure(new Figure(type, color));
}

void Engine::createFigure(Figure* figure)
{
	// Ќельз€ создавать новую фигуру до того момента, пока стара€ не опустилась
	if (currentFigure_.first)
		return;

	std::vector<int> relativeLayoutValues = getRelativeLayoutValues(figure);

	std::vector<sf::Vector2f> tilePositions(relativeLayoutValues.size());
	int i = 0;
	for (auto it = relativeLayoutValues.begin(); it != relativeLayoutValues.end(); ++it)
	{
		tilePositions[i].x = *it % 2;
		tilePositions[i].y = *it / 2;
		++i;
	}
	currentFigure_ = std::make_pair(figure, tilePositions);
}

void Engine::drawFigures()
{
	Figure* figure = currentFigure_.first;
	std::vector<sf::Vector2f>& tilePositions = currentFigure_.second;
	sf::Sprite sprite = tileHelper_->getTileSprite(figure);

	if (clock_.getElapsedTime().asSeconds() > constants::TimerDelay)
	{
		moveFigure(Figure::FigureMoveDirection::Down);
		clock_.restart();
	}

	int i = 0;
	for (auto it = tilePositions.begin(); it != tilePositions.end(); ++it)
	{
		sprite.setPosition(tilePositions[i].x * constants::TileSide, tilePositions[i].y * constants::TileSide);
		window_->draw(sprite);
		++i;
	}
}

void Engine::moveFigure(Figure::FigureMoveDirection dir)
{
	std::vector<sf::Vector2f>& tilePositions = currentFigure_.second;

	switch (dir)
	{
	case Figure::FigureMoveDirection::Left:
		for (int i = 0; i < tilePositions.size(); i++)
			tilePositions[i].x--;
		break;
	case Figure::FigureMoveDirection::Right:
		for (int i = 0; i < tilePositions.size(); i++)
			tilePositions[i].x++;
		break;
	case Figure::FigureMoveDirection::Down:
		for (int i = 0; i < tilePositions.size(); i++)
			tilePositions[i].y++;
		break;
	default:
		break;
	}
}

void Engine::rotateFigure()
{
	std::vector<sf::Vector2f>& tilePositions = currentFigure_.second;
	// “очка, относительно которой будет происходить вращение
	sf::Vector2f centerPoint = tilePositions[1];

	for (int i = 0; i < tilePositions.size(); i++)
	{
		int x = tilePositions[i].y - centerPoint.y;
		int y = tilePositions[i].x - centerPoint.x;
		tilePositions[i].x = centerPoint.x - x;
		tilePositions[i].y = centerPoint.y + y;
	}
}

std::vector<int> Engine::getRelativeLayoutValues(Figure* figure)
{
	std::vector<int> res;
	auto find_it = constants::RelativeLayoutTableValues.find(figure->getType());
	if (find_it != constants::RelativeLayoutTableValues.end())
		res = (*find_it).second;

	return res;
}
