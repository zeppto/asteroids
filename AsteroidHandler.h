#ifndef ASTEROIDHANDLER_H
#define ASTEROIDHANDLER_H
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "SmallAsteroid.h"
#include "Alien.hpp"

class AsteroidHandler : public sf::Drawable
{
private:
	Asteroid * * asterods;

	int nrOfAstroids,
		capacity,
		nrToSpwan;
	sf::Sprite playerRefrens;

	void expand();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	AsteroidHandler(int capacity = 10);
	~AsteroidHandler();
	AsteroidHandler(const AsteroidHandler& other);
	AsteroidHandler& operator=(const AsteroidHandler& other);


	int getNrOfAsteroid() const;
	sf::Sprite getASprite(int index) const;
	bool getAAstroidCollition(int index, sf::Sprite collider);

	void setPlayerSpritRef(sf::Sprite playerSprite);

	void starSpwan();
	bool remove(int index);
	void addMedium(sf::Vector2f pos);
	void addSmall(sf::Vector2f pos);
	void resetNrToSpwan();

	void update(float dt);
};


#endif // !ASTEROIDHANDLER_H
