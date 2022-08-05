#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <random>
#include "Food.h"
#include "Food_List.h"
#include "Creature_List.h"
using namespace std;



//TODO GRAPH OF GENERATIONS IN NEW WINDOW

void evolve(sf::RenderWindow *w, FoodL *fl, CreatureL *cl, int n)
{
	//CreatureL newList(w);
	int c = cl->getSize();
	int i;
	int count = 0;
	float effA = 0;
	for (i = 0; i < c; i++) {//Reproduce for each creature according to efficiency and xp
		Creature cur = cl->getCtr(i);
		float e = cur.getEff();
		float xp = cur.getXp();
		effA += e;
		

		while (e <= xp) {
			
			cl->addCtr(cl->getCtr(i).reproduce());
			xp = xp-e;
			count++;
			cout << xp << endl;

		}
	}
	cout << endl << "AVERAGE EFF:" << effA / c << endl;
	for (i = 0; i < c; i++) {//Kill off last generation
		cl->removeCtr(0);
		cl->drawCtrList();
		w->clear(sf::Color(240, 240, 240, 255));
	}
	/*for (i = 0; i < count; i++) {
		cl->addCtr(newList.getCtr(i));
	}*/

	for (int j = 0; j <= n; j++) {//Generate new foods for next gen
		Food newFood(sf::Vector2f(rand() % 1920 + 1, rand() % 1080 + 1));
		fl->addFood(newFood);
	}
	cout << cl->getSize() << endl;
}






int main()
{
	

	int n = 70;//number of foods 70

	// create the window--------------------
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window");
	
	window.setFramerateLimit(165);
	
	





	sf::RectangleShape rect;

	rect.setSize(sf::Vector2f(100, 100));
	rect.setOrigin(sf::Vector2f(0, 50));
	rect.setPosition(sf::Vector2f(500, 500));

	float sc = 1;


	//sprite------------------------
	Creature cr2(sf::Vector2f(1770, 400), 1, 1);//test creature


	sf::RectangleShape line;
	line.setSize(sf::Vector2f(200, 3));
	
	CreatureL ctrL(&window);

	//create first  generation
	ctrL.addCtr(cr2);
	ctrL.addCtr(cr2.reproduce());
	ctrL.addCtr(cr2.reproduce());
	ctrL.addCtr(cr2.reproduce());
	ctrL.addCtr(cr2.reproduce());
	ctrL.addCtr(cr2.reproduce());
	ctrL.addCtr(cr2.reproduce());
	ctrL.addCtr(cr2.reproduce());

	

	FoodL FoodL(&window);
	
	for (int j = 0; j <= n; j++) { // food for first generation
		Food newFood(sf::Vector2f(rand() % 1920 + 1, rand() % 1080 + 1));
		FoodL.addFood(newFood);
	}


;

	//FoodL.removeFood(0);
	//FoodL.removeFood(0);
	//FoodL.removeFood(0);
	

	



	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		
		}
		

		


		// clear the window with color
		window.clear(sf::Color(240,240,240,255));
		
	
		

		// draw everything here...
		// window.draw(...);
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			window.draw(rect);
			rect.setScale(sc, sc);
			sc = (sc + 0.1) ;

		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
	
			sc = 50.0;

		}*/
	
		//food.Draw(&window);

		//line2[0] = sf::Vertex(cr.m_creature.getPosition());
		//line2[1] = sf::Vertex(FoodL.getFood(cr.findClosestFood(&FoodL)).getPos());
		
		//window.draw(cr.m_creature);
		//;
		if (FoodL.getSize() <= 0) {
			evolve(&window ,&FoodL, &ctrL, n);
		}
		if (FoodL.getSize() != 0) {
			FoodL.drawFoodList();

			ctrL.drawCtr(&FoodL);
			
			//int cl = cr.findClosestFood(&FoodL);
		}
		//cout << ctrL.getSize() << endl;
		//FoodL.getFood(cl).Draw(&window);
		//game.gameLoop(&rect);
		
		
		
		
		// end the current frame
		window.display();
		
		

	}

	return 0;
}