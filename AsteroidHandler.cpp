#include "AsteroidHandler.h"

void AsteroidHandler::expand()
{
	Asteroid** temp = new Asteroid*[capacity + 5];
	for (int i = 0; i < nrOfAstroids; i++)
		temp[i] = asterods[i];
	delete[] asterods;
	asterods = temp;
	temp = nullptr;

	capacity += 5;
}

void AsteroidHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < nrOfAstroids; i++)
		target.draw(*asterods[i], states);
}

AsteroidHandler::AsteroidHandler(int capacity)
{
	this->capacity = capacity;
	nrToSpwan = 3;
	nrOfAstroids = 0;

	asterods = new Asteroid*[capacity];
}

AsteroidHandler::~AsteroidHandler()
{
	for (int i = 0; i < nrOfAstroids; i++)
		delete asterods[i];
	delete[] asterods;
}

AsteroidHandler::AsteroidHandler(const AsteroidHandler & other)
{
	this->capacity = other.capacity;
	this->nrOfAstroids = other.nrOfAstroids;
	this->nrToSpwan = other.nrToSpwan;

	asterods = new Asteroid*[other.capacity];
	for (int i = 0; i < other.nrOfAstroids; i++)
		asterods[i] = new Asteroid(*other.asterods[i]);
}

AsteroidHandler & AsteroidHandler::operator=(const AsteroidHandler & other)
{
	if (this != &other)
	{
		for (int i = 0; i < nrOfAstroids; i++)
			delete asterods[i];
		delete[] asterods;

		this->capacity = other.capacity;
		this->nrOfAstroids = other.nrOfAstroids;
		this->nrToSpwan = other.nrToSpwan;

		asterods = new Asteroid*[other.capacity];
		for (int i = 0; i < other.nrOfAstroids; i++)
			asterods[i] = new Asteroid(*other.asterods[i]);
	}
	return *this;
}

int AsteroidHandler::getNrOfAsteroid() const
{
	return nrOfAstroids;
}

sf::Sprite AsteroidHandler::getASprite(int index) const
{
	return asterods[index]->getSprite();
}

bool AsteroidHandler::getAAstroidCollition(int index, sf::Sprite collider)
{
	return asterods[index]->getAstroidCollition(collider);
}

void AsteroidHandler::setPlayerSpritRef(sf::Sprite playerSprite)
{
	this->playerRefrens = playerSprite;
}

void AsteroidHandler::starSpwan()
{
	if (nrOfAstroids == 0)
	{
		nrToSpwan++;
		if(nrToSpwan == capacity)
			expand();
		for (int i = 0; i < nrToSpwan; i++)
		{
			asterods[i] = new BigAsteroid();
			while (asterods[i]->getAstroidCollition(playerRefrens))
			{
				asterods[i]->setPos(rand() % 1600, rand() % 900);
			}
			nrOfAstroids++;
		}
	}

}

bool AsteroidHandler::remove(int index)
{
	if (index < nrOfAstroids)
	{
		if (dynamic_cast<BigAsteroid*> (asterods[index]))
		{
			for (int i = 0; i < 2; i++)
				addMedium(asterods[index]->getPos());
		}
		else if (dynamic_cast<MediumAsteroid*> (asterods[index]))
		{
			for (int i = 0; i < 2; i++)
				addSmall(asterods[index]->getPos());
		}
		delete asterods[index];
		asterods[index] = asterods[nrOfAstroids - 1];
		asterods[nrOfAstroids - 1] = nullptr;
		nrOfAstroids--;
	}
	return index < nrOfAstroids;
}

void AsteroidHandler::addMedium(sf::Vector2f pos)
{
	if (nrOfAstroids == capacity)
		expand();

	asterods[nrOfAstroids] = new MediumAsteroid(pos);
	nrOfAstroids++;
}

void AsteroidHandler::addSmall(sf::Vector2f pos)
{
	if (nrOfAstroids == capacity)
		expand();

	asterods[nrOfAstroids] = new SmallAsteroid(pos);
	nrOfAstroids++;
}

void AsteroidHandler::resetNrToSpwan()
{
	nrToSpwan = 3;
}

void AsteroidHandler::update(float dt)
{
	starSpwan();
	for (int i = 0; i < nrOfAstroids; i++)
		asterods[i]->Update(dt);
}
