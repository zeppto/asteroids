#ifndef ASTEROID_HPP
#define ASTEROID_HPP
#include "Entity.hpp"
#include <iostream>
#include <ctime>

class Asteroid : public Entity
{
public:
	Asteroid();

	void Update(float dt);
	sf::Sprite getSprite() const;
	sf::Vector2f getPos() const;

	void setScale(sf::Vector2f scale);
	void setPos(float x, float y);
	void setSprite(sf::String fileName, sf::IntRect sheetRecr, int originX, int originY);
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif // !ASTEROID_HPP
