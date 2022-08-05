#ifndef CREATURE_HEADER
#define CREATURE_HEADER





#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Food_List.h"
#include <iostream>
#include <random>


using namespace std;

class Creature
{
public:
	Creature() ;

	//PARAM: Vector2f position, speed, effeciency
	//POST: Constructs creature with given param values
	Creature(sf::Vector2f pos, float s, float e);

	~Creature() {};
	
	//PARAM: Food list pointer
	//POST: MOVES towards closest food and RETURNS line from creature to food
	sf::RectangleShape hunt(FoodL *l);

	//PARAM: Food list pointer
	//POST: RETURNS index of closest food
	int findClosestFood(const FoodL *l) const;

	//PARAM: Vector2f position
	//POST: RETURNS distance between position and creature
	float getDist(sf::Vector2f p) const;

	//PARAM: Render window pointer
	//POST: Draws rectangle shape member to window 
	void draw(sf::RenderWindow *w);


	//POST: RETURNS copy of creature with randomized mutation
	Creature reproduce();

	float getEff();

	int getXp();

	float getSpeed();

private:
	int m_xp;

	float speed;//move distance multiplier

	float eff;//xp needed to produce exactly 1 offspring (lower = better efficiency)

	sf::Vector2f m_pos;

	sf::RectangleShape m_creature;

};





#endif // !CREATURE_HEADER