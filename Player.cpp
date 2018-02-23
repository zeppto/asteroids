#include "Player.hpp"
#include <math.h>
#include <iostream>

const float deg2rad = (3.14159f / 180.0f);

Player::Player(int playerNumber)
{
	sf::String fileName = "../Resources/playerShip1.png";//"../Resources/astroid.png";

	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (!mTexture.loadFromFile(fileName))
	{
		// Handle error: Print error message.
		std::cout << "ERROR: Player image could not be loaded.\n---" << std::endl;
	}
	else
	{
		mSpriteSheet.setTexture(mTexture);
	}
	setDirection(sf::Vector2f(0.0f, 0.0f));
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 40, 40));
	mSpriteSheet.setPosition(500, 500);
	mSpriteSheet.setOrigin(20, 20);
	mAcc = sf::Vector2f(0.0f, 0.0f);
	bulletTimer = 0;
}

void Player::Update(float dt)
{
	movement(dt);
	shoot(dt);
	bulletHandeler.update(dt);
}

void Player::movement(float dt)
{
	setDirectionY(sin(mSpriteSheet.getRotation() * deg2rad));
	setDirectionX(cos(mSpriteSheet.getRotation() * deg2rad));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mSpriteSheet.rotate(0.2f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mSpriteSheet.rotate(-0.2f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		mAcc += getDirection()*0.5f;
	}
	else
	{
		mAcc -= mAcc *dt;
		/*if (mAcc.x > 0)
			mAcc.x -= 0.2f;
		else if (mAcc.x < 0)
			mAcc.x += 0.2f;

		if (mAcc.y > 0)
			mAcc.y -= 0.2f;
		else if (mAcc.y < 0)
			mAcc.y += 0.2f;*/
	}

	edgeOfScreen(mSpriteSheet);

	mSpriteSheet.move(mAcc * dt);
}

void Player::shoot(float dt)
{
 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletTimer > 20)
	{
		bulletHandeler.add(getDirection(), mSpriteSheet.getPosition(), mSpriteSheet.getRotation());
		bulletTimer = 0;
	}
	bulletTimer += 100*dt;
}

void Player::die()
{
	//starta dödss animation
	//vänta tills den är över
	//restarta spelaren(plasera den i mitten med ett mindre liv eller dör och spelet är slut)
	//game over skreen när spelaren inte har mer liv(vill bara ha ett liv så direckt game over skren)
	//temp om spelaren dör respawn i mitten
	mSpriteSheet.setPosition(750, 450);
	mAcc = sf::Vector2f(0, 0);
	mSpriteSheet.setRotation(270);
}

sf::Vector2f Player::getPos() const
{
	return mSpriteSheet.getPosition();
}

int Player::getNrOfBullets() const
{
	return bulletHandeler.getNrOfBullets();
}

bool Player::getBulletCollision(int index, sf::Sprite collider)
{
	return bulletHandeler.getABulletCollision(index, collider);
}

bool Player::getPlayerCollision(sf::Sprite collider)
{
	return mSpriteSheet.getGlobalBounds().intersects(collider.getGlobalBounds());
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(bulletHandeler, states);
	target.draw(mSpriteSheet, states);
}