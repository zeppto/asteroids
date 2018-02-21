#ifndef BULLETHANDELER_H
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

	void add(sf::Vector2f direction, sf::Vector2f position, float rotation);
	bool remove(int index);
	void bulletLife();

	void update(float dt);
};


#endif // !BULLETHANDELER_H

