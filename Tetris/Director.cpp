#include "Director.h"

Director::Director(sf::RenderWindow* window) :
	window_(window)
{
	createFigure(FigureType::T, FigureColor::Cyan);
}

void Director::keyPressed(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Left:
		moveFigure(FigureMoveDirection::Left);
		break;
	case sf::Keyboard::Right:
		moveFigure(FigureMoveDirection::Right);
		break;
	case sf::Keyboard::Down:
		moveFigure(FigureMoveDirection::Down);
		break;
	default:
		rotateFigure();
		break;
	}
}

void Director::makeTileSprites(const sf::Texture& texture)
{
	tileSprites.clear();
	for (int i = 0, img_count = 0; i < FigureColor::Count; ++i, img_count += constants::TileSide)
	{
		sf::Sprite sprite(texture);
		sprite.setTextureRect(sf::IntRect(img_count, 0, constants::TileSide, constants::TileSide));
		tileSprites.emplace((FigureColor)i, sprite);
	}
}

sf::Sprite Director::getTileSprite(Figure* figure)
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

void Director::createFigure(FigureType type, FigureColor color)
{
	Figure* figure = new Figure(type, color);
	std::vector<int> values = figure->getFigureValues();

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

void Director::drawFigures()
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

void Director::moveFigure(FigureMoveDirection dir)
{
	std::vector<sf::Vector2f>& tilePositions = currentFigure_.second;

	switch (dir)
	{
	case Left:
		for (int i = 0; i < tilePositions.size(); i++)
			tilePositions[i].x--;
		break;
	case Right:
		for (int i = 0; i < tilePositions.size(); i++)
			tilePositions[i].x++;
		break;
	case Down:
		for (int i = 0; i < tilePositions.size(); i++)
			tilePositions[i].y++;
		break;
	default:
		break;
	}
}

void Director::rotateFigure()
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
