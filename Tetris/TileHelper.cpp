#include "TileHelper.h"

TileHelper* TileHelper::instance_ = nullptr;

TileHelper* TileHelper::getInstance()
{
	if (nullptr == instance_)
		instance_ = new TileHelper();

	return instance_;
}

TileHelper::TileHelper()
{
}

TileHelper::~TileHelper()
{
	delete instance_;

	for (auto& sprite : tileSprites_)
		delete sprite.second;
}

void TileHelper::makeTileSprites(const sf::Texture& texture)
{
	tileSprites_.clear();
	for (int i = 0, img_count = 0; i < FigureColor::ColorCount; ++i, img_count += constants::TileSide)
	{
		sf::Sprite* sprite = new sf::Sprite(texture);
		sprite->setTextureRect(sf::IntRect(img_count, 0, constants::TileSide, constants::TileSide));
		tileSprites_.emplace((FigureColor)i, sprite);
	}
}

sf::Sprite* TileHelper::getTileSprite(FigureColor color)
{
	sf::Sprite* res;

	auto sprite_it = tileSprites_.find(color);
	if (sprite_it == tileSprites_.end() || (*sprite_it).first == FigureColor::NoColor)
		res = nullptr;
	else
		res = (*sprite_it).second;

	return res;
}

sf::Sprite* TileHelper::getTileSprite(Figure* figure)
{
	if (nullptr == figure)
		return nullptr;

	return getTileSprite(figure->getColor());
}
