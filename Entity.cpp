#include "Entity.hpp"

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}
Entity::Entity()
{
	originX = 20;
	originY = 20;
}

void Entity::update(float dt, sf::Sprite & mSpriteSheet)
{
}

void Entity::edgeOfScreen(sf::Sprite & mSpriteSheet)
{
	if (mSpriteSheet.getPosition().x < -originX)
		mSpriteSheet.setPosition(1600.0f + originX, mSpriteSheet.getPosition().y);
	if (mSpriteSheet.getPosition().x > 1600.0f + originX)
		mSpriteSheet.setPosition(-originX, mSpriteSheet.getPosition().y);
	if (mSpriteSheet.getPosition().y < -originY)
		mSpriteSheet.setPosition(mSpriteSheet.getPosition().x, 900.0f + originY);
	if (mSpriteSheet.getPosition().y > 900.0f + originY)
		mSpriteSheet.setPosition(mSpriteSheet.getPosition().x, -originY);
}

sf::Vector2f Entity::getDirection() const
{
	return direction;
}

float Entity::getSpeed() const
{
	return speed;
}

float Entity::getOriginX() const
{
	return originX;
}

float Entity::getOriginY() const
{
	return originY;
}

void Entity::setDirection(sf::Vector2f direction)
{
	this->direction = direction;
}

void Entity::setDirectionX(float x)
{
	direction.x = x;
}

void Entity::setDirectionY(float y)
{
	direction.y = y;
}

void Entity::setSpeed(float speed)
{
	this->speed = speed;
}

void Entity::setOriginX(float originX)
{
	this->originX = originX;
}

void Entity::setOriginY(float originY)
{
	this->originY = originY;
}
