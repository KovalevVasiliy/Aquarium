#ifndef SPRITES_H
#define SPRITES_H

#include <SFML\Graphics.hpp>
#include <iostream>

 class Sprites
{
public:
	Sprites() 
	{
		HerbivoreEatT.loadFromFile("HrbvEat.png");
		HerbivoreMoveT.loadFromFile("HrbvMove.png");
		HerbivoreReprodT.loadFromFile("HrbvReprod.png");
		PredatorEatT.loadFromFile("PrdEat.png");
		PredatorMoveT.loadFromFile("PrdMove.png");
		PredatorReprodT.loadFromFile("PrdReprod.png");
		PlanktonMoveT.loadFromFile("PlnkMove.png");
		PlanktonReprodT.loadFromFile("PlnkReprod.png");
		HerbivoreEat.setTexture(HerbivoreEatT);
		HerbivoreMove.setTexture(HerbivoreMoveT);
		HerbivoreReprod.setTexture(HerbivoreReprodT);
		PredatorEat.setTexture(PredatorEatT);
		PredatorMove.setTexture(PredatorMoveT);
		PredatorReprod.setTexture(PredatorReprodT);
		PlanktonMove.setTexture(PlanktonMoveT);
		PlanktonReprod.setTexture(PlanktonReprodT);
		HerbivoreEat.scale(0.3, 0.3);
		HerbivoreMove.scale(0.3, 0.3);
		HerbivoreReprod.scale(0.3, 0.3);
		PredatorEat.scale(0.3, 0.3);
		PredatorMove.scale(0.3, 0.3);
		PredatorReprod.scale(0.3, 0.3);
		PlanktonMove.scale(0.3, 0.3);
		PlanktonReprod.scale(0.3, 0.3);
	}
	~Sprites(){}

	 sf::Sprite HerbivoreEat;
	 sf::Sprite HerbivoreMove;
	 sf::Sprite HerbivoreReprod;
	 sf::Sprite PredatorEat;
	 sf::Sprite PredatorMove;
	 sf::Sprite PredatorReprod;
	 sf::Sprite PlanktonMove;
	 sf::Sprite PlanktonReprod;
private:
	 sf::Texture HerbivoreEatT;
	 sf::Texture HerbivoreMoveT;
	 sf::Texture HerbivoreReprodT;
	 sf::Texture PredatorEatT;
	 sf::Texture PredatorMoveT;
	 sf::Texture PredatorReprodT;
	 sf::Texture PlanktonMoveT;
	 sf::Texture PlanktonReprodT;
	
};

//C:\\Users\\home\\Source\\Repos\\Aquarium\\aquarium\\

#endif