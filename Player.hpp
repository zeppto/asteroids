#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Entity.hpp"
#include "BulletHandler.h"

#include <SFML\Graphics.hpp>

class Player : public Entity
{
public:
	Player(int playerNumber);

	void Update(float dt);

	void movement(float dt);
	void shoot(float dt);
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	sf::Vector2f mAcc;
	BulletHandler bulletHandeler;
	float bulletTimer;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif