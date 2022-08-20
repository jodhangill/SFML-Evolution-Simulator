#ifndef FOOD_HEADER
#define FOOD_HEADER





#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>


using namespace std;


class Food
{
public:

	//PARAM: Vector2f position
	//POST: Construct food at position
	Food(sf::Vector2f pos) ;

	~Food() {};

	//PARAM: Render window pointer
	//POST: DRAWS food to render window
	void Draw(sf::RenderWindow *w);

	//PARAM: Index
	//POST: Sets value of index member
	void setInd(int n);

	//POST: RETURNS index member
	int getInd() const;

	//POST: RETURNS position of food
	sf::Vector2f getPos() const;
	

private:
	int m_ind;//Index in food list

	sf::Vector2f m_position;
	sf::CircleShape m_food;
};


#endif // !FOOD_HEADER