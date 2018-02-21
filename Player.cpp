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
		mSpriteSheet.rotate(0.2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mSpriteSheet.rotate(-0.2);
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

int Player::getNrOfBullets() const
{
	return bulletHandeler.getNrOfBullets();
}

bool Player::getBulletCollision(int index, sf::Sprite collider)
{
	return bulletHandeler.getABulletCollision(index, collider);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(bulletHandeler, states);
	target.draw(mSpriteSheet, states);
}