#include "aquarium.h"
#include <cstdlib>


Aquarium::Aquarium(coordinates size) :size(size){}

Aquarium::Aquarium(coordinates size, std::list<Organism*> org)
	:size(size)
{
	this->listOfOrganisms = org;
	int sum = 0;
	for (auto i : org)
	{
		sum += i->getCoef();
		if (sum > size.first*size.second)
		{
			throw Exception(4);
		}
	}
}
void Aquarium::randFill(int numOfHerbivore, int numOfPlanktones,int numOfPredators)
{
	std::list<Organism*> listOfOrganisms;
	Sprites* sprites = new Sprites;
	int chance = numOfPlanktones;
	while (chance)
	{
		coordinates posOfPlankton;
		int radOfView = rand() % radOfViewPlanktonDelta + radOfViewPlankton;
		int radOfDisp = rand() % radOfDispPlanktonDelta + radOfDispPlankton;
		int lifeTime = rand() % lifeTimePlanktonDelta + lifeTimePlankton;
		posOfPlankton.first = rand() % size.first + 0;
		posOfPlankton.second = rand() % size.second + 0;
		posOfPlankton.third = rand() % size.third + 0;
		bool sex = rand() % 2;
		try
		{
			listOfOrganisms.push_back(new Plankton(posOfPlankton, radOfDisp, radOfView, lifeTime,sex, sprites));
		}
		catch (Exception &ex)
		{
			std::cout << ex.what() << std::endl;
		}
		chance--;
	}

	chance = numOfHerbivore;
	while (chance)
	{
		coordinates posOfHerbivore;
		int radOfView = rand() % radOfViewHerbivoreDelta + radOfViewHerbivore;
		int radOfDisp = rand() % radOfDispHerbivoreDelta + radOfDispHerbivore;
		int lifeTime = rand() % lifeTimeHerbivoreDelta + lifeTimeHerbivore;
		int eattime = rand() % eatTimeHerbivoreDelta + eatTimeHerbivore;
		posOfHerbivore.first = rand() % size.first + 0;
		posOfHerbivore.second = rand() % size.second + 0;
		posOfHerbivore.third = rand() % size.third + 0;
		bool sex = rand() % 2;
		try
		{
			listOfOrganisms.push_back(new Herbivore(posOfHerbivore, radOfDisp, radOfView, lifeTime, eattime,sex, sprites));
		}
		catch (Exception &ex)
		{
			std::cout << ex.what() << std::endl;
		}
		chance--;
	}

	chance = numOfPredators;
	while (chance)
	{
		coordinates posOfPredators;
		int radOfView = rand() % radOfViewPredatorDelta + radOfViewPredator;
		int radOfDisp = rand() % radOfDispPredatorDelta + radOfDispPredator;
		int lifeTime = rand() % lifeTimePredatorDelta + lifeTimePredator;
		int eattime = rand() % eatTimePredatorDelta + eatTimePredator;
		posOfPredators.first = rand() % size.first + 0;
		posOfPredators.second = rand() % size.second + 0;
		posOfPredators.third = rand() % size.third + 0;
		bool sex = rand() % 2;
		try
		{
			listOfOrganisms.push_back(new Predator(posOfPredators, radOfDisp, radOfView, lifeTime, eattime,sex, sprites));
		}
		catch (Exception &ex)
		{
			std::cout << ex.what() << std::endl;
		}
		chance--;
	}
	this->listOfOrganisms = listOfOrganisms;
}
Aquarium::~Aquarium()
{
	//listOfOrganisms.~list();
}

void Aquarium::update()
{
	std::set<Organism*> del;
	for (auto it=listOfOrganisms.begin();it!=listOfOrganisms.end();it++)
	{
		(*it)->update(listOfOrganisms, coordinates(size.first - 1, size.second - 1, size.third - 1),del);

		if (isFull())
		{
			throw Exception(4);
		}
	}
	for (auto it = listOfOrganisms.begin(); it != listOfOrganisms.end();)
	{
		if (del.find(*it) != del.end())
		{
			
			it=listOfOrganisms.erase(it++);
		}
		else
		{
			it++;
		}
	}
}

void  Aquarium::addOrganism(Organism* organism)
{
	int sum = organism->getCoef();
	for (auto i : listOfOrganisms)
	{
		sum += i->getCoef();
		if (sum > size.first*size.second)
		{
			throw Exception(4);
		}
	}

	listOfOrganisms.push_back(organism);
	
}
bool Aquarium::isAlive()
{	
	int fish = 0;
	int plank = 0;
	int pred = 0;
	for (auto i : listOfOrganisms)
	{
		if (i->getCoef() == coefOfHerbivore)
		{
			fish += 1;
		}
		else if (i->getCoef() == coefOfPlancton)
		{
			plank += 1;
		}
		else
		{
			pred += 1;
		}
	}
	if (fish == 0 || plank == 0 || pred == 0)
	{
		std::cout << fish << "fish/" << plank << "plank/pred" << pred << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}
void Aquarium::show()
{
	int fish = 0;
	int plank = 0;
	int pred = 0;
	std::cout << "   !" << listOfOrganisms.size() << std::endl;
	for (auto i : listOfOrganisms)
	{
		if (i->getCoef() == coefOfHerbivore)
		{
			fish += 1;
		}
		else if (i->getCoef() == coefOfPlancton)
		{
			plank += 1;
		}
		else
		{
			pred += 1;
		}
	}
	std::cout << "\nF" << fish << std::endl;
	std::cout << "Pl" << plank << std::endl;
	std::cout << "Pr" << pred << std::endl;
}

std::list<Organism*> Aquarium::getListOfOrganisms()
{ 
	return listOfOrganisms; 
}
bool Aquarium::isFull()
{
	int sum = 0;
	for (auto i : listOfOrganisms)
	{
		sum += i->getCoef();
		if (sum > size.first*size.second*size.third)
		{
			return true;
		}
	}
	return false;
}
