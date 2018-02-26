#include "AlienHandeler.h"

void AlienHandeler::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (aAlien != nullptr)
		target.draw(*aAlien, states);
}

AlienHandeler::AlienHandeler()
{
	aAlien = nullptr;
	alienSpwanTimer = rand() % 5000 + 5000;
}

AlienHandeler::~AlienHandeler()
{
	delete aAlien;
}

AlienHandeler::AlienHandeler(const AlienHandeler & other)
{
	this->alienSpwanTimer = other.alienSpwanTimer;

	if (other.aAlien != nullptr)
		aAlien = new Alien(*other.aAlien);
	else
		aAlien = nullptr;
}

AlienHandeler & AlienHandeler::operator=(const AlienHandeler & other)
{
	if (this != &other)
	{
		delete aAlien;

		this->alienSpwanTimer = other.alienSpwanTimer;

		if (other.aAlien != nullptr)
			aAlien = new Alien(*other.aAlien);
	}
	return *this;
}

void AlienHandeler::alienSpwaner()
{
	if (aAlien == nullptr)
	{
		alienSpwanTimer--;
	}
	if (alienSpwanTimer < 0)
	{
		alienSpwanTimer = rand() % 10000 + 5000;
		aAlien = new Alien();
	}
}

void AlienHandeler::remove()
{
	delete aAlien;
	aAlien = nullptr;
}

bool AlienHandeler::alienExist()
{
	return aAlien != nullptr;
}

void AlienHandeler::setAlienPlayerPosRefrens(sf::Vector2f playerPos)
{
	if (aAlien != nullptr)
		aAlien->setPlayerPosRefrens(playerPos);
}

sf::Sprite AlienHandeler::getSprite() const
{
	return aAlien->getSprite();
}

bool AlienHandeler::getABulletCollision(int index, sf::Sprite collider)
{
	return aAlien->getABulletCollision(index, collider);
}

int AlienHandeler::getNrOfBullets() const
{
		return aAlien->getNrOfBullets();
}

void AlienHandeler::update(float dt)
{
	alienSpwaner();

	if (aAlien != nullptr)
		aAlien->Update(dt);
}
