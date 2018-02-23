#include "Alien.hpp"

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
		x = rand() % (1600 + 110) - 55;
		y = rand() % (900 + 110) - 55;
	} while ((x > 1600 + getOriginX() || x < -getOriginX()) && y > 900 + getOriginY() || y < -getOriginY());
	spriteSheet.setPosition(rand() % (1600 + 110) - 55, rand() % (900 + 110) - 55);
	setSpeed(3);
	shootTimer = 0;
}

void Alien::setPlayerPosRefrens(sf::Vector2f playerPos)
{
	playerPosRefrens = playerPos;
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

		//temp rotation
		bulletHandeler.add(bulletDirection, spriteSheet.getPosition(), spriteSheet.getRotation());
		shootTimer = 0;
	}
	shootTimer++;

}

