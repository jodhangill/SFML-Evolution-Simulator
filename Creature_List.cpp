#include "Creature_List.h"

CreatureL::CreatureL(sf::RenderWindow *w)
{
	m_window = w;
	list_size = 0;
}

CreatureL::~CreatureL()
{
	ctr_list.clear();
}


void CreatureL::addCtr(Creature ctr)
{
	ctr_list.push_back(ctr);
	++list_size;

};

void CreatureL::removeCtr(int i)
{
	sf::Clock clock;
	if (list_size >= 1) {
		//death animation

		
		ctr_list.erase(ctr_list.begin() + i);

		--list_size;
	}
}

void CreatureL::drawCtrList()
{
	if (ctr_list.size() >= 1) {
		for (unsigned int i = 0; i <= ctr_list.size() - 1; i++) {
			ctr_list[i].draw(m_window);
		}
	}
}


Creature CreatureL::getCtr(int i)
{
	if (list_size >= 1) {
		return ctr_list.at(i);
	}
}

int CreatureL::getSize()
{
	return list_size;
}

void CreatureL::drawCtr(FoodL *foodL)
{
	cout << ctr_list.size() << endl;
	cout << foodL->getSize() << endl;
	if (ctr_list.size() >= 1) {
		for (unsigned int i = 0; i <= ctr_list.size() - 1 ; i++) {
			if (foodL->getSize() > 0) {
				ctr_list[i].draw(m_window);
				m_window->draw(ctr_list[i].hunt(foodL));
			}
		}
	}
}