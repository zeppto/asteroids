#ifndef ALIEN_H
#define ALIEN_H
#include "Entity.hpp"
#include "BulletHandler.h"

class Alien : public Entity
{
private:

	sf::Texture texture;
	sf::Sprite spriteSheet;
	BulletHandler bulletHandeler;
	int shootTimer;
	float bulletRotation;
	sf::Vector2f bulletDirection,
		playerPosRefrens;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Alien();

	void setPlayerPosRefrens(sf::Vector2f playerPos);
	sf::Sprite getSprite() const;
	bool getABulletCollision(int index, sf::Sprite collider);
	int Alien::getNrOfBullets() const;

	void Update(float dt);
};


#endif // !ALIEN_H

