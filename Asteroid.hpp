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
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif // !ASTEROID_HPP
