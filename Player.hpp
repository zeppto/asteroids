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
	void die();
	//borde g�ra att det finns en player bullet handeler som tar hand om spelarens bullets s� detta inte beh�vs
	sf::Vector2f getPos() const;
	int getNrOfBullets() const;
	bool getBulletCollision(int index, sf::Sprite collider);
	bool getPlayerCollision(sf::Sprite collider);
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	sf::Vector2f mAcc;
	BulletHandler bulletHandeler;
	float bulletTimer;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif