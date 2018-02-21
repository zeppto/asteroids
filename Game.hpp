#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Player.hpp"
#include "Asteroid.hpp"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "AsteroidHandler.h"

class Game : public sf::Drawable
{
public:
	Game();

	void Update(float dt);

private:
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;
	Player mPlayer;
	AsteroidHandler astroidHandler;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif