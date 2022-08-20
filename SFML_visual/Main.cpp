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
		}
	}
	for (i = 0; i < c; i++) {//Kill off last generation
		cl->removeCtr(0);
		cl->drawCtrList();
		w->clear(sf::Color(240, 240, 240, 255));
	}
	/*for (i = 0; i < count; i++) {
		cl->addCtr(newList.getCtr(i));
	}*/

	for (int j = 1; j <= n; j++) {//Generate new foods for next gen
		Food newFood(sf::Vector2f(rand() % 1920 + 1, rand() % 1080 + 1));
		fl->addFood(newFood);
	}
}






int main()
{
	
	//Create Window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Evolution Simulator");
	window.setFramerateLimit(165);
	
	
	//Create menu graphic
	sf::RectangleShape rect;

	rect.setSize(sf::Vector2f(2000, 120));
	rect.setPosition(sf::Vector2f(263, 535));
	rect.setFillColor(sf::Color(150, 150, 150, 255));


	//Create menu text
	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "err" << endl;
	}

	sf::Text text;
	sf::Text enter;

	text.setFont(font); 
	text.setString("INITIAL FOOD: [ENTER VALUE]");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color(100,100,100,255));
	text.setPosition(sf::Vector2f(960, 540));
	text.setOrigin(sf::Vector2f(text.getCharacterSize()*7, 12));
	text.setStyle(sf::Text::Bold);
	text.setOutlineThickness(5);
	text.setOutlineColor(sf::Color(10, 10, 10, 255));

	enter.setFont(font);
	enter.setString("PRESS ENTER TO CONTINUE");
	enter.setCharacterSize(75);
	enter.setFillColor(sf::Color(100, 100, 100, 0));
	enter.setPosition(sf::Vector2f(263, 700));
	enter.setStyle(sf::Text::Bold);

	//Store input
	string input = "INITIAL FOOD: ";

	int nFood = -1;//number of foods per generation
	int nCtr = -1;//initial number of creatures

	//menu wiht inputs

	/* MENU 1: food entry ------------------------------------------------------- */
	bool menu = true;
	while (menu) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			// Input Amount of initial food
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 58 && event.text.unicode > 47 && nFood < 100) {
					input += static_cast<char>(event.text.unicode);
					text.setFillColor(sf::Color(150, 255, 255, 255));
					text.setString(input);
					int x = text.getPosition().x;
					string foodString = text.getString().substring(14, text.getString().getSize());
					nFood = stoi(foodString);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				if (input.size() == 15) {
					input.pop_back();
					text.setString("INITIAL FOOD: 0");
					nFood = 0;

				}
				if (input.size() > 15) {
					input.pop_back();
					text.setFillColor(sf::Color(150, 255, 255, 255));
					text.setString(input);
					int x = text.getPosition().x;
					string foodString = text.getString().substring(14, text.getString().getSize());
					nFood = stoi(foodString);
				}

			}
			//Invalid amount (99 max to avoid slowdown)
			if (nFood > 99 || nFood < 1) {
				text.setFillColor(sf::Color::Red);
				enter.setFillColor(sf::Color(100, 100, 100, 0));
			}
			//Confirm value
			else {
				enter.setFillColor(sf::Color(100, 100, 100, 255));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					menu = false;
				}
			}
		}

		window.clear(sf::Color(200, 200, 200, 255));
		window.draw(rect);
		window.draw(text);
		window.draw(enter);
		window.display();
	}
	
	/* MENU 2: creature entry ------------------------------------------------------- */
	menu = true;
	input = "INITIAL PODS: ";
	text.setString("INITIAL PODS: [ENTER VALUE]");
	while (menu) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			// Input Amount of initial creatures
			if (event.type == sf::Event::TextEntered) {
				cout << "check" << endl;
				if (event.text.unicode < 58 && event.text.unicode > 47 && nCtr < 100) {
					input += static_cast<char>(event.text.unicode);
					text.setFillColor(sf::Color(32, 243, 110, 255));
					text.setString(input);
					int x = text.getPosition().x;
					string ctrString = text.getString().substring(14, text.getString().getSize());
					nCtr = stoi(ctrString);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				if (input.size() == 15) {
					input.pop_back();
					text.setString("INITIAL PODS: 0");
					nCtr = 0;

				}
				if (input.size() > 15) {
					input.pop_back();
					text.setFillColor(sf::Color(32, 243, 110, 255));
					text.setString(input);
					int x = text.getPosition().x;
					string ctrString = text.getString().substring(14, text.getString().getSize());
					nCtr = stoi(ctrString);
				}

			}
			//Invalid amount (99 max to avoid slowdown)
			if (nCtr > 99 || nCtr < 1) {
				text.setFillColor(sf::Color::Red);
				enter.setFillColor(sf::Color(100, 100, 100, 0));
			}
			//Confirm value
			else {
				enter.setFillColor(sf::Color(100, 100, 100, 255));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					menu = false;
				}
			}
		}

		window.clear(sf::Color(200, 200, 200, 255));
		window.draw(rect);
		window.draw(text);
		window.draw(enter);
		window.display();
	}

	//initialize creature list
	CreatureL ctrL(&window);

	//create initial creatures------------------------
	for (int i = 1; i <= nCtr; i++) {
		Creature ctr(sf::Vector2f(rand() % 1920 + 1, rand() % 1080 + 1), 1, 1);//Default: efficiency = 1, speed = 1
		ctrL.addCtr(ctr);
	}
	
	//initialize food list
	FoodL FoodL(&window);
	
	//create initial foods
	for (int j = 1; j <= nFood; j++) { // food for first generation
		Food newFood(sf::Vector2f(rand() % 1920 + 1, rand() % 1080 + 1));
		FoodL.addFood(newFood);
	}

	// RUN PROGRAM-----------------------------------------
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

			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 58 && event.text.unicode > 47) {
					input += static_cast<char>(event.text.unicode);
					text.setFillColor(sf::Color::Blue);
					text.setString(input);
				}
			}

		
		}
		// clear the window with color
		window.clear(sf::Color(240,240,240,255));
		//evolve to next generation when food is depleted
		if (FoodL.getSize() <= 0) {
			evolve(&window ,&FoodL, &ctrL, nFood);
		}
		//draw creatures hunting food
		if (FoodL.getSize() >= 0) {
			FoodL.drawFoodList();
			ctrL.drawCtr(&FoodL);
		}
		// end the current frame
		window.display();
		
		

	}
	return 0;
}