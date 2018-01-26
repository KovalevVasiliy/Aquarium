#ifndef CONSTANTS_H
#define CONSTANTS_H

///coef
static const int coefOfPlancton = 1;
static const int coefOfHerbivore = 3;
static const int coefOfPredator = 4;
///Planktons
static const int radOfViewPlankton=2;
static const int radOfViewPlanktonDelta = 2;
static const int radOfDispPlankton=2;
static const int radOfDispPlanktonDelta = 1;
static const int lifeTimePlankton=5;
static const int lifeTimePlanktonDelta = 5;
static const int childrenOfPlankton = 5;
///Herbivores
static const int radOfViewHerbivore=6;
static const int radOfViewHerbivoreDelta = 2;
static const int radOfDispHerbivore=4;
static const int radOfDispHerbivoreDelta = 2;
static const int lifeTimeHerbivore=20;
static const int lifeTimeHerbivoreDelta = 10;
static const int eatTimeHerbivore = 7;
static const int eatTimeHerbivoreDelta = 2;
static const int childrenOfHerbivore = 3;

///Predators
static const int radOfViewPredator=6;
static const int radOfViewPredatorDelta = 4;
static const int radOfDispPredator=6;
static const int radOfDispPredatorDelta = 1;
static const int lifeTimePredator=15;
static const int lifeTimePredatorDelta = 5;
static const int eatTimePredator = 4;
static const int eatTimePredatorDelta = 3;
static const int childrenOfPredator = 2;

#endif