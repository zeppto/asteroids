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

void AsteroidHandler::starSpwan()
{
	if (nrOfAstroids == 0)
	{
		nrToSpwan++;
		if(nrToSpwan == capacity)
			expand();
		for (int i = 0; i < nrToSpwan; i++)
		{
			asterods[i] = new Asteroid();//lägtill stora astroider
			nrOfAstroids++;
		}
	}

}

bool AsteroidHandler::remove(int index)
{
	return false;
}

void AsteroidHandler::update(float dt)
{
}
