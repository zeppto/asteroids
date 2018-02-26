#include "Alien.hpp"

const float rad2deg = (180.0f / 3.14159f);

void Alien::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(spriteSheet, states);
	target.draw(bulletHandeler, states);
}

Alien::Alien()
{
	srand(time(NULL));
	setDirectionX(rand() % 200 - 100);
	setDirectionY(rand() % 200 - 100);
	sf::String fileName = "../Resources/tempAlien.png";
	if (!texture.loadFromFile(fileName))
	{
		std::cout << "Error! image could not be loaded!.." << std::endl;
	}
	else
	{
		spriteSheet.setTexture(texture);
	}
	spriteSheet.setTextureRect(sf::IntRect(0, 0, 50, 50));
	spriteSheet.setOrigin(25, 25);
	setOriginX(25);
	setOriginY(25);
	int x,
		y;
	do
	{
 		y = rand() % (900 + 210) - 100;
  	} while (y < 900 + getOriginY() && y > -getOriginY());
	do
	{
		x = rand() % (1600 + 210) - 100;
	} while (x < 1600 + getOriginX() && x > -getOriginX());

 	spriteSheet.setPosition(x, y);
	setSpeed(2);
	shootTimer = 0;
}

void Alien::setPlayerPosRefrens(sf::Vector2f playerPos)
{
	playerPosRefrens = playerPos;
}

sf::Sprite Alien::getSprite() const
{
	return spriteSheet;
}

bool Alien::getABulletCollision(int index, sf::Sprite collider)
{
	return bulletHandeler.getABulletCollision(index, collider);
}

int Alien::getNrOfBullets() const
{
	return bulletHandeler.getNrOfBullets();
}

void Alien::Update(float dt)
{
	spriteSheet.move(getDirection() * dt* getSpeed());
	edgeOfScreen(spriteSheet);
	bulletHandeler.update(dt);
	if (shootTimer > 3000)
	{
		sf::Vector2f distens = playerPosRefrens - spriteSheet.getPosition();
		float lengt = sqrt((distens.x*distens.x) + (distens.y + distens.y));
		if (lengt != 0)
			bulletDirection = sf::Vector2f(distens.x / lengt, distens.y / lengt);
		else
			bulletDirection = sf::Vector2f(0,0);

		//funkar ibland och inte ibland 
		bulletRotation = asin(bulletDirection.y) * rad2deg;

		bulletHandeler.add(bulletDirection, spriteSheet.getPosition(), bulletRotation);
		shootTimer = 0;
	}
	shootTimer++;

}

