#ifndef CREATUREL_HEADER
#define CREATUREL_HEADER

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "Creature.h"

class CreatureL
{
public:
	//PARAM: Render window pointer
	//POST: Constructs list of creatures for given windoww
	CreatureL(sf::RenderWindow *w);

	~CreatureL();

	//PARAM: Creature to add
	//POST: Add creature to list
	void addCtr(Creature ctr);

	//PARAM: Index
	//POST: Removes (kills) creature at index
	void removeCtr(int i);

	//PARAM: Index
	//POST: RETURNS creature at index
	Creature getCtr(int i);

	//POST: RETURNS size of list
	int getSize();

	//PARAM: Food list pointer
	//POST: Hunts for each creature. Draws creature and line
	void drawCtr(FoodL *foodL);

	//POST: Draws creatures only
	void drawCtrList();

private:
	std::vector<Creature> ctr_list;

	sf::RenderWindow *m_window;

	int list_size;
};

#endif // !CREATUREL_HEADER

