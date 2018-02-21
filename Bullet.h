#ifndef BULLET_H
#define BULLET_H
#include "Entity.hpp"

class Bullet : public Entity
{
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	int lifeTimer;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Bullet(sf::Vector2f direction, sf::Vector2f position, float rotation, float speed = 300);

	int getLifeTimer() const;

	void Update(float dt);
};

#endif // !Bullet
