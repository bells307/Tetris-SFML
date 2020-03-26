#include "Engine.h"
#include "TileHelper.h"

Engine::Engine(sf::RenderWindow* window) :
	window_(window)
{
	// Текстура тайла
	sf::Texture* tileTexture = new sf::Texture();
	tileTexture->loadFromFile(constants::TileTextureFileName);

	TileHelper::getInstance()->makeTileSprites(*tileTexture);

	field_ = new Field();

	createFigure(Figure::getRandomFigure());
}

Engine::~Engine()
{
	delete field_;
}

void Engine::keyPressed(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Left:
		moveCurrentFigure(FigureMoveDirection::Left);
		break;
	case sf::Keyboard::Right:
		moveCurrentFigure(FigureMoveDirection::Right);
		break;
	case sf::Keyboard::Down:
		moveCurrentFigure(FigureMoveDirection::Down);
		break;
	case sf::Keyboard::Up:
		rotateCurrentFigure();
		break;
	default:
		break;
	}
}

void Engine::createFigure(FigureType type, FigureColor color)
{
	createFigure(new Figure(type, color));
}

void Engine::createFigure(Figure* figure)
{
	// Нельзя создавать новую фигуру до того момента, пока старая не опустилась
	if (getCurrentFigure())
		return;

	std::vector<int> relativeLayoutValues = getRelativeLayoutValues(figure);

	// Позиции тайлов новой фигуры
	TilePositionsMap tilePositions(relativeLayoutValues.size());

	int i = 0;
	for (const auto& val : relativeLayoutValues)
	{
		tilePositions[i].x = val % 2;
		tilePositions[i].y = val / 2;
		++i;
	}

	FigureColor color = figure->getColor();
	FieldPointsArray& fieldPoints = getField()->getFieldPoints();
	for (const auto& pos : tilePositions)
	{
		fieldPoints[pos.x][pos.y].color = color;
	}

	setCurrentFigure(figure, tilePositions);
}

void Engine::setTilePositions(TilePositionsMap& newTilePositions)
{
	TilePositionsMap& currentFigureTilePositions = getCurrentFigureTilePositions();
	FigureColor color = getCurrentFigure()->getColor();
	FieldPointsArray& fieldPoints = getField()->getFieldPoints();

	for (const auto& pos : currentFigureTilePositions)
	{
		if (pos.x >= constants::FieldWidth || pos.y >= constants::FieldHeight)
			break;

		fieldPoints[pos.x][pos.y].color = FigureColor::NoColor;
	}

	for (const auto& pos : newTilePositions)
	{
		if (pos.x >= constants::FieldWidth || pos.y >= constants::FieldHeight)
			break;

		fieldPoints[pos.x][pos.y].color = color;
	}

	currentFigureTilePositions = newTilePositions;
}

void Engine::drawFigures()
{
	if (clock_.getElapsedTime().asSeconds() > constants::TimerDelay)
	{
		moveCurrentFigure(FigureMoveDirection::Down);
		clock_.restart();
	}

	FieldPointsArray& fieldPoints = getField()->getFieldPoints();
	sf::Sprite* sprite;

	for (int i = 0; i < constants::FieldWidth; ++i)
	{
		for (int j = 0; j < constants::FieldHeight; ++j)
		{
			sprite = TileHelper::getInstance()->getTileSprite(fieldPoints[i][j].color);
			if (sprite == nullptr)
				continue;

			sprite->setPosition(i * constants::TileSide, j * constants::TileSide);
			getWindow()->draw(*sprite);
		}
	}
}

void Engine::moveCurrentFigure(FigureMoveDirection dir)
{
	TilePositionsMap tilePositions = getCurrentFigureTilePositions();

	switch (dir)
	{
	case FigureMoveDirection::Left:
		for (auto& pos : tilePositions)
			pos.x--;
		break;
	case FigureMoveDirection::Right:
		for (auto& pos : tilePositions)
			pos.x++;
		break;
	case FigureMoveDirection::Down:
		for (auto& pos : tilePositions)
			pos.y++;
		break;
	default:
		break;
	}

	setTilePositions(tilePositions);
}

void Engine::rotateCurrentFigure()
{
	TilePositionsMap tilePositions = getCurrentFigureTilePositions();
	// Точка, относительно которой будет происходить вращение
	TilePosition centerPoint = tilePositions[1];

	for (auto& pos : tilePositions)
	{
		int x = pos.y - centerPoint.y;
		int y = pos.x - centerPoint.x;
		pos.x = centerPoint.x - x;
		pos.y = centerPoint.y + y;
	}

	setTilePositions(tilePositions);
}

std::vector<int> Engine::getRelativeLayoutValues(Figure* figure)
{
	std::vector<int> res;
	auto find_it = constants::RelativeLayoutTableValues.find(figure->getType());
	if (find_it != constants::RelativeLayoutTableValues.end())
		res = (*find_it).second;

	return res;
}
