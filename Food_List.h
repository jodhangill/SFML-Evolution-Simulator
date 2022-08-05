#ifndef FOODL_HEADER
#define FOODL_HEADER



#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "Food.h"


using namespace std;


class FoodL
{
public:
	//PARAM: Render window pointer
	//POST: Constructs list of food for given window
	FoodL(sf::RenderWindow *w);

	~FoodL();

	//PARAM: Food to add
	//POST: Adds food to list
	void addFood(Food food);

	//PARAM: Pointer to food to remove
	//POST: Remove specific food from list
	void removeFood(Food *food);

	//PARAM: Index
	//POST: Removed food at index
	void removeFood(int i);

	//PARAM: Index
	//POST: RETURNS food at index
	Food getFood(int i) const;

	//POST: RETURNS size of list
	unsigned int getSize() const;

	//POST: draws each food to render window
	void drawFoodList();


private:
	int listSize;
	int foodInd;

	std::vector<Food> food_list;
	sf::RenderWindow *m_window;

};

#endif 