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
}

void Asteroid::Update(float dt)
{
	mSpriteSheet.move(getDirection() * dt);

	edgeOfScreen(mSpriteSheet);
}

void Asteroid::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
}
