#ifndef BULLET_H
#define BULLET_H
#include "Entity.hpp"
#include <iostream>


class Bullet : public Entity
{
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	int lifeTimer;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Bullet(sf::Vector2f direction, sf::Vector2f position, float rotation, float speed = 500);

	int getLifeTimer() const;
	bool colliding(sf::Sprite colider);

	void Update(float dt);
};

#endif // !Bullet
