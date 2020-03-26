#ifndef TileHelper_h
#define TileHelper_h

#include "Constants.h"
#include "Types.h"

// ���� ������ - � ������
typedef std::map<FigureColor, sf::Sprite*> FigureSpritesMap;

// ����� ��� ������ � �������
class TileHelper
{
public:
	~TileHelper();

	static TileHelper* getInstance();

	// ������� ������� �� ������ ��� ������� ����� �����
	void makeTileSprites(const sf::Texture& texture);
	// �������� ������
	sf::Sprite* getTileSprite(FigureColor color);
	sf::Sprite* getTileSprite(Figure* figure);

private:
	TileHelper();

private:
	static TileHelper* instance_;
	FigureSpritesMap tileSprites_;
};

#endif // !TileHelper_h
