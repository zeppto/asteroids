#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Player.hpp"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "AsteroidHandler.h"
#include "AlienHandeler.h"

class Game : public sf::Drawable
{
public:
	Game();

	void Update(float dt);

private:
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;
	Player mPlayer;
	AlienHandeler alienHandler;
	AsteroidHandler astroidHandler;
	sf::Text text;
	sf::Font font;
	int score;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif