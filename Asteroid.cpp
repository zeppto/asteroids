#include "Asteroid.hpp"

Asteroid::Asteroid()
{
	setDirectionX(rand() % 200 - 100);
	setDirectionY(rand() % 200 - 100);
	//bra för temp textur   
	mTexture.setSmooth(true);
}

void Asteroid::Update(float dt)
{
	mSpriteSheet.move(getDirection() * dt);
	mSpriteSheet.rotate(0.01f);
	edgeOfScreen(mSpriteSheet);
}

sf::Vector2f Asteroid::getPos() const
{
	return mSpriteSheet.getPosition();
}

void Asteroid::setSprite(sf::String fileName, sf::IntRect sheetRecr, int originX, int originY)
{
	if (!mTexture.loadFromFile(fileName))
	{
		std::cout << "Error! image could not be loaded!.." << std::endl;
	}
	else
	{
		mSpriteSheet.setTexture(mTexture);
	}
	mSpriteSheet.setTextureRect(sheetRecr);
	mSpriteSheet.setOrigin(originX, originY);
}

bool Asteroid::getAstroidCollition(sf::Sprite collider)
{
	return mSpriteSheet.getGlobalBounds().intersects(collider.getGlobalBounds());
}

void Asteroid::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
}

sf::Sprite Asteroid::getSprite() const
{
	return mSpriteSheet;
}

void Asteroid::setScale(sf::Vector2f scale)
{
	mSpriteSheet.setScale(scale);
}

void Asteroid::setPos(float x, float y)
{
	mSpriteSheet.setPosition(x, y);
}
