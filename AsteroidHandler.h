#ifndef ASTEROIDHANDLER_H
#define ASTEROIDHANDLER_H
#include "Asteroid.hpp"

class AsteroidHandler : public sf::Drawable
{
private:
	Asteroid * * asterods;
	int nrOfAstroids,
		capacity,
		nrToSpwan;

	void expand();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	AsteroidHandler(int capacity = 10);
	~AsteroidHandler();
	AsteroidHandler(const AsteroidHandler& other);
	AsteroidHandler& operator=(const AsteroidHandler& other);

	void starSpwan();
	bool remove(int index);

	void update(float dt);
};


#endif // !ASTEROIDHANDLER_H
