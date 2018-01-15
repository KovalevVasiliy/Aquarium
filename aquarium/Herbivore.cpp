#include "Herbivore.h"



Herbivore::Herbivore(coordinates location_, int radOfDisp_, int radOfview_,
	int lifeTime_, int starvation_, int eatTime_) :Fish(location_, radOfDisp_, radOfview_,
		lifeTime_, starvation_, eatTime_)
{
	if ((radOfView > 9) || (radOfView < 6)||
		(radOfDisp > 6) || (radOfDisp < 4)||
		(lifeTime > 11) || (lifeTime < 8) ||
		(eatTime > 5) || (eatTime < 4) ||
		(radOfDisp > radOfView))
	{
		throw Exception(2);
	}
}


Herbivore::~Herbivore()
{}

void Herbivore::move(std::map<Organism&, int> neighbors, coordinates sizeAqua)
{
	if (neighbors.size() != 0)
	{
		float minDist = (radOfDisp * 2 + location.first + location.second)*neighbors.size();
		coordinates newLoc(location.first, location.second);
		for (int i = (-1)*radOfDisp; i <= radOfDisp; i++)
		{
			if ((location.first + i <= sizeAqua.first) && (location.first + i >= 0))
			{
				for (int j = (-1)*radOfDisp; j <= radOfDisp; j++)
				{
					if ((location.second + j <= sizeAqua.second) && (location.second + j >= 0))
					{
						int distance = 0;
						for (auto it = neighbors.begin(); it != neighbors.end(); it++)
						{
							distance = distance + fabs(it->first.getLocation().first - location.first + i)
								+ fabs(it->first.getLocation().second - location.second + j);
						}
						if (distance < minDist)
						{
							minDist = distance;
							newLoc = coordinates(location.first + i, location.second + j);
						}
					}
				}
			}
		}
		moveDisl(newLoc);
	}
	else
	{
		/*int newx = rand() % radOfDisp;
		if (newx > sizeAqua.first)
		{
			newx = sizeAqua.first;
		}
		int newy = rand() % radOfDisp;
		if (newy > sizeAqua.second)
		{
			newy = sizeAqua.second;
		}
		moveDisl(coordinates(location.first + newx, location.second + newy));*/
	}

}