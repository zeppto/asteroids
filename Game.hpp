#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Player.hpp"
#include "AsteroidHandler.h"
#include "AlienHandeler.h"
#include <sstream>
#include "BaseState.h"

class Game : public BaseState
{
public:
	Game();

	BaseState* update(float dt);
	void addPoints(int points);
	void handelEvent(sf::Event event);
private:
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;
	Player mPlayer;
	AlienHandeler alienHandler;
	AsteroidHandler astroidHandler;
	sf::Text scoreCounter;
	sf::Font font;
	int score;
	std::string playerName;
	BaseState* returnToUpdate;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif