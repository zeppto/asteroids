#include "Alien.hpp"

Alien::Alien()
{
	srand(time(NULL));
	setSprite("../Resources/tempAlien.png", sf::IntRect(0, 0, 50, 50), 25, 25);
	setOriginX(25);
	setOriginY(25);
	int x,
		y;
	do
	{
		x = rand() % (1600 + 110) - 55;
		y = rand() % (900 + 110) - 55;
	} while ((x > 1600 + getOriginX() || x < -getOriginX()) && y > 900 + getOriginY() || y < -getOriginY());
	setPos(rand() % (1600 + 110) - 55, rand() % (900 + 110) - 55);
}

void Alien::Update(float dt)
{
	Asteroid::Update(dt);
	bulletHandeler.update(dt);
	int shootTimer = 0;
	if (shootTimer > 1000)
	{
		//temp directiom and rotation
		bulletHandeler.add(getDirection(), getPos(), 0);
		shootTimer = 0;
	}
	shootTimer++;

}

