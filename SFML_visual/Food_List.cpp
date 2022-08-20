#include "Food_List.h"


FoodL::FoodL(sf::RenderWindow *w) 
{
	m_window = w;
	foodInd = 0;
	listSize = 0;

};

FoodL::~FoodL()
{
	food_list.clear();
}


void FoodL::addFood(Food food)
{
	food_list.push_back(food);
	//food.setInd(foodInd);
	++listSize;
	//++foodInd;


};

void FoodL::removeFood(Food *food)
{
	int n = food->getInd() ;
	food_list.erase(food_list.begin() + n);

	--listSize;
	//--foodInd;
	

}

void FoodL::removeFood(int i)
{
	if (listSize >= 1) {
		food_list.erase(food_list.begin() + i);

		--listSize;
	}

	//--foodInd;


}


void FoodL::drawFoodList() {
	
	if (listSize >= 0) {
		for (int i = 0; i < food_list.size() ; i++) {
			food_list[i].Draw(m_window);
		}
	}
	else {
		throw out_of_range("drawFoodList(i): List is too small");
	}

};

Food FoodL::getFood(int i) const
{
	if (listSize >= 1) {
		return food_list.at(i);
	}
	else {
		throw out_of_range("getFood(i): List is too small");
	}
	
}

unsigned int FoodL::getSize() const
{
	return food_list.size();
}