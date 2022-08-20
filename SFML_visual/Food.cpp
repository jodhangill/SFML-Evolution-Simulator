#include "Food.h"



Food::Food(sf::Vector2f pos) 
{

	m_position = pos;
	m_food.setOrigin(sf::Vector2f(5, 5));
	



};



void Food::Draw(sf::RenderWindow *w) 
{

	m_food.setPosition(m_position);
	m_food.setFillColor(sf::Color(150, 255, 255, 255));
	m_food.setRadius(5);
	m_food.setOutlineThickness(1);
	m_food.setOutlineColor(sf::Color(15, 25, 25, 255));
	w->draw(m_food);
	

};

int Food::getInd() const
{

	return m_ind;

}

void Food::setInd(int n)
{
	m_ind = n;

}

sf::Vector2f Food::getPos() const
{
	return m_position;
}