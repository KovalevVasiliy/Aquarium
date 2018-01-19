#ifndef DRAWER_H
#define DRAWER_H
#include "aquarium.h"
#include <vector>
#include <SFML\Graphics.hpp>
class Drawer
{
public:
	Drawer(sf::RenderWindow* renderWindow, coordinates coord, std::string aquaImagePath);
	void drawOrganisms(std::vector<Organism*> organisms);
	void drawAquarium(
	);
	~Drawer();
private:
	sf::RenderWindow* renderWindow;
	coordinates size;
	sf::Sprite s_map;
};
#endif DRAWER_H