#ifndef FISH_H
#define FISH_H

#include "Organism.h"

class Fish :
	public Organism
{
public:
	Fish(coordinates location_, int radOfDisp_, int radOfview_,	int lifeTime_,
		int eatTime_, int pauseReprodaction_, int coef_, sf::Sprite* body_);
	virtual ~Fish();
	//virtual void update(std::vector<Organism*>& organisms, coordinates sizeAqua) = 0;
	virtual bool eat(std::vector<Organism*>& organisms) = 0;
protected:
	const int eatTime;
	int starvation;
};

#endif