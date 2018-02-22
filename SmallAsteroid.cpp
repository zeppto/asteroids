#include "SmallAsteroid.h"

SmallAsteroid::SmallAsteroid(sf::Vector2f pos)
{
	setSprite("../Resources/astroid.png", sf::IntRect(0, 0, 40, 40), 20, 20);
	setPos(pos.x, pos.y);
}
