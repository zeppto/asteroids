#include "Bullet.h"

void Bullet::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
}

Bullet::Bullet(sf::Vector2f direction, sf::Vector2f position, float rotation, float speed)
{
	sf::String fileName = "../Resources/bullet.png";

	if (!mTexture.loadFromFile(fileName))
	{
		std::cout << "ERROR: Bullet image could not be loaded.\n---" << std::endl;
	}
	else
	{
		mSpriteSheet.setTexture(mTexture);
	}
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 10, 5));
	mSpriteSheet.setOrigin(5, 2.5f);
	mSpriteSheet.setPosition(position);
	mSpriteSheet.setRotation(rotation);
	setSpeed(speed);
	setDirection(direction);
	lifeTimer = 0;
}

int Bullet::getLifeTimer() const
{
	return lifeTimer;
}

void Bullet::Update(float dt)
{
	mSpriteSheet.move(getDirection() * getSpeed()* dt);

	edgeOfScreen(mSpriteSheet);
	lifeTimer++;
}
