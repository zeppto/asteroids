#include "MediumAsteroid.h"

MediumAsteroid::MediumAsteroid(sf::Vector2f pos)
{
	setSprite("../Resources/astroid.png", sf::IntRect(0, 0, 40, 40), 20, 20);
	setPos(pos.x, pos.y);
	setScale(sf::Vector2f(2.2f, 2.2f));
	setOriginX(20 * 2.2f);
	setOriginY(20 * 2.2f);
}
