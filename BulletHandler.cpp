#include "BulletHandler.h"

void BulletHandler::expand()
{
	Bullet** temp = new Bullet*[capacity + 5];
	for (int i = 0; i < nrOfBullets; i++)
		temp[i] = bullets[i];
	delete[] bullets;
	bullets = temp;
	temp = nullptr;
	capacity += 5;
}

void BulletHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for(int i = 0; i < nrOfBullets; i++)
		target.draw(*bullets[i], states);
}

BulletHandler::BulletHandler(int capacity)
{
	this->capacity = capacity;
	nrOfBullets = 0;
	bullets = new Bullet*[capacity];
}

BulletHandler::~BulletHandler()
{
	for (int i = 0; i < nrOfBullets; i++)
		delete bullets[i];
	delete[] bullets;
}

BulletHandler::BulletHandler(const BulletHandler & other)
{
	this->capacity = other.capacity;
	this->nrOfBullets = other.nrOfBullets;

	bullets = new Bullet*[other.capacity];
	for (int i = 0; i < other.nrOfBullets; i++)
		bullets[i] = new Bullet(*other.bullets[i]);
}

BulletHandler & BulletHandler::operator=(const BulletHandler & other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->nrOfBullets; i++)
			delete bullets[i];
		delete[] bullets;

		this->nrOfBullets = other.nrOfBullets;
		this->capacity = other.capacity;

		bullets = new Bullet*[other.capacity];
		for (int i = 0; i < other.nrOfBullets; i++)
			bullets[i] = new Bullet(*other.bullets[i]);
	}
	return *this;
}

int BulletHandler::getNrOfBullets() const
{
	return nrOfBullets;
}

void BulletHandler::add(sf::Vector2f direction, sf::Vector2f position, float rotation, float speed)
{
	if (capacity == nrOfBullets)
		expand();

	bullets[nrOfBullets] = new Bullet(direction, position, rotation, speed);
	nrOfBullets++;
}

bool BulletHandler::remove(int index)
{
	if (index < nrOfBullets)
	{
		delete bullets[index];
		bullets[index] = bullets[nrOfBullets - 1];
		bullets[nrOfBullets - 1] = nullptr;
		nrOfBullets--;
	}
	return index != -1;
}

void BulletHandler::bulletLife()
{
	for (int i = 0; i < nrOfBullets; i++)
	{
		if (bullets[i]->getLifeTimer() >= 2000)
			remove(i);
	}
}

bool BulletHandler::getABulletCollision(int index, sf::Sprite collider)
{
	bool isTrue = false;
	if (index < nrOfBullets)
	{
		isTrue = bullets[index]->colliding(collider);
		if(isTrue)
			remove(index);
	}
	return isTrue;
}

void BulletHandler::update(float dt)
{
	for (int i = 0; i < nrOfBullets; i++)
		bullets[i]->Update(dt);
	bulletLife();
}
