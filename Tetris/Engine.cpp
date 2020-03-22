#include "Engine.h"

Engine::Engine(sf::RenderWindow* window) :
	window_(window)
{
	createFigure(Figure::FigureType::T, Figure::FigureColor::Cyan);
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
	default:
		rotateFigure();
		break;
	}
}

void Engine::makeTileSprites(const sf::Texture& texture)
{
	tileSprites.clear();
	for (int i = 0, img_count = 0; i < Figure::FigureColor::Count; ++i, img_count += constants::TileSide)
	{
		sf::Sprite sprite(texture);
		sprite.setTextureRect(sf::IntRect(img_count, 0, constants::TileSide, constants::TileSide));
		tileSprites.emplace((Figure::FigureColor)i, sprite);
	}
}

sf::Sprite Engine::getTileSprite(Figure* figure)
{
	if (nullptr == figure)
		return sf::Sprite();

	sf::Sprite res;

	auto sprite_it = tileSprites.find(figure->getColor());
	if (sprite_it == tileSprites.end())
		res = sf::Sprite();
	else
		res = (*sprite_it).second;

	return res;
}

void Engine::createFigure(Figure::FigureType type, Figure::FigureColor color)
{
	Figure* figure = new Figure(type, color);
	std::vector<int> values = getFigureValues(figure);

	std::vector<sf::Vector2f> tilePositions(values.size());
	int i = 0;
	for (auto it = values.begin(); it != values.end(); ++it)
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
	std::vector<sf::Vector2f> tilePositions = currentFigure_.second;
	sf::Sprite sprite = getTileSprite(figure);

	int i = 0;
	for (auto it = tilePositions.begin(); it != tilePositions.end(); ++it)
	{
		sprite.setPosition(tilePositions[i].x * 18, tilePositions[i].y * 18);
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
	sf::Vector2f centerPoint = tilePositions[1];

	for (int i = 0; i < tilePositions.size(); i++)
	{
		int x = tilePositions[i].y - centerPoint.y;
		int y = tilePositions[i].x - centerPoint.x;
		tilePositions[i].x = centerPoint.x - x;
		tilePositions[i].y = centerPoint.y - y;
	}
}

std::vector<int> Engine::getFigureValues(Figure* figure)
{
	std::vector<int> res;
	auto find_it = constants::FigureValues.find(figure->getType());
	if (find_it != constants::FigureValues.end())
		res = (*find_it).second;

	return res;
}
