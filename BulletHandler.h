#ifndef BULLETHANDELER_H
#define BULLETHANDELER_H
#include "Bullet.h"

class BulletHandler : public sf::Drawable
{
private:
	Bullet * * bullets;
	int nrOfBullets,
		capacity;

	void expand();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	BulletHandler(int capacity = 10);
	~BulletHandler();
	BulletHandler(const BulletHandler& other);
	BulletHandler& operator=(const BulletHandler& other);

	int getNrOfBullets() const;

	void add(sf::Vector2f direction, sf::Vector2f position, float rotation, float speed = 500);
	bool remove(int index);
	void bulletLife();
	bool getABulletCollision(int index, sf::Sprite collider);

	void update(float dt);
};


#endif // !BULLETHANDELER_H

