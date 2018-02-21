#include "MediumAsteroid.h"

MediumAsteroid::MediumAsteroid(sf::Vector2f pos)
{
	setPos(pos.x, pos.y);
	setScale(sf::Vector2f(2.2f, 2.2f));
}
