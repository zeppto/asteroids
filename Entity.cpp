#include "Entity.hpp"

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}
Entity::Entity()
{
}

void Entity::update(float dt, sf::Sprite & mSpriteSheet)
{
}

void Entity::edgeOfScreen(sf::Sprite & mSpriteSheet)
{
	if (mSpriteSheet.getPosition().x < -20.0f)
		mSpriteSheet.setPosition(1620.0f, mSpriteSheet.getPosition().y);
	if (mSpriteSheet.getPosition().x > 1620.0f)
		mSpriteSheet.setPosition(-20.0f, mSpriteSheet.getPosition().y);
	if (mSpriteSheet.getPosition().y < -20.0f)
		mSpriteSheet.setPosition(mSpriteSheet.getPosition().x, 920.0f);
	if (mSpriteSheet.getPosition().y > 920.0f)
		mSpriteSheet.setPosition(mSpriteSheet.getPosition().x, -20.0f);
}

sf::Vector2f Entity::getDirection() const
{
	return direction;
}

float Entity::getSpeed() const
{
	return speed;
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
