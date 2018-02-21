#include "BigAsteroid.h"

BigAsteroid::BigAsteroid()
{
	setPos(rand() % 1600, rand() % 900);
	setScale(sf::Vector2f(5, 5));
}
