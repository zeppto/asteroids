#ifndef ALIEN_H
#define ALIEN_H
#include "Asteroid.hpp"
#include "BulletHandler.h"

class Alien : public Asteroid
{
private:
	sf::Texture texture;
	sf::Sprite spriteSheet;
	BulletHandler bulletHandeler;

public:
	Alien();

	void Update(float dt);
};


#endif // !ALIEN_H

