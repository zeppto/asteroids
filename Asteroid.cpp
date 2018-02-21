#include "Asteroid.hpp"

Asteroid::Asteroid()
{
	sf::String fileName = "../Resources/astroid.png";

	if (!mTexture.loadFromFile(fileName))
	{
		std::cout << "ERROR: Player image could not be loaded.\n---" << std::endl;
	}
	else
	{
		mSpriteSheet.setTexture(mTexture);
	}
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 40, 40));
	mSpriteSheet.setOrigin(20, 20);

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
