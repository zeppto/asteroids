#include "BigAsteroid.h"

BigAsteroid::BigAsteroid()
{
	//ändra texturen
	setSprite("../Resources/astroid.png", sf::IntRect(0, 0, 40, 40), getOriginX(), getOriginY());
	setPos(rand() % 1600, rand() % 900);
	setScale(sf::Vector2f(5, 5));
	setOriginX(20 * 5);
	setOriginY(20 * 5);
}
