#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <iostream>
#include <SFML\Graphics.hpp>

class Entity : public sf::Drawable
{
private:
	sf::Vector2f direction;
	float speed = 0.5f,
		originX,
		originY;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Entity();
	void update(float dt, sf::Sprite& mSpriteSheet);
	void edgeOfScreen(sf::Sprite & mSpriteSheet);


	sf::Vector2f getDirection() const;
	float getSpeed() const;
	float getOriginX() const;
	float getOriginY() const;

	void setDirection(sf::Vector2f direction);
	void setDirectionX(float x);
	void setDirectionY(float y);
	void setSpeed(float speed);
	void setOriginX(float originX);
	void setOriginY(float originY);
};


#endif // !ENTITY_HPP 
