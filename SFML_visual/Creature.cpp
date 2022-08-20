#include "Creature.h"


Creature::Creature()
{
	m_creature.setSize(sf::Vector2f(15, 15));
	m_creature.setOrigin(sf::Vector2f(7.5, 7.5));
	m_xp = 0;
}

Creature::Creature(sf::Vector2f pos, float s, float e)
{
	m_creature.setSize(sf::Vector2f(15, 15));
	m_creature.setOrigin(sf::Vector2f(7.5, 7.5));
	m_creature.setPosition(pos);
	m_creature.setOutlineThickness(1);
	m_creature.setOutlineColor(sf::Color(0, 0, 0));
	m_xp = 0;
	speed = s;
	eff = e;
	m_creature.setFillColor(sf::Color(std::min((int)(20 + e * 12),255), std::max((int)(255 - e*12), 0), std::min((int)(100 + e*10), 255), 255));//colour represent efficiency	GREEN = MORE EFFICIENT		PINK = LESS EFFICIENT
}

sf::RectangleShape Creature::hunt(FoodL *l)
{
	if (l->getSize() != 0) {
		int i = findClosestFood(l);
		sf::Vector2f pos = m_creature.getPosition();
		sf::Vector2f fPos = l->getFood(i).getPos();
		float angle = atan2(pos.y - fPos.y, pos.x - fPos.x) * 180 / 3.1415926536;
		m_creature.setRotation(angle);
		
		float angleRads = (3.1415926536 / 180)*(angle); //convert to radians
		m_creature.move(-speed*cos(angleRads),-speed*sin(angleRads));

		float dist = getDist(fPos);
		
		//test for collision
		if (dist < 18) {
				
			l->removeFood(i);
			m_xp++;
			
		}

		sf::RectangleShape line(sf::Vector2f(dist, 1));
		line.setOrigin(sf::Vector2f(dist, 1));
		line.setPosition(pos);
		line.setRotation(angle);
		line.setFillColor(sf::Color(50, 50, 50, 50));
		return line;
	}

	

}


int Creature::findClosestFood(const FoodL *l) const //TODO: SPEED UP RUNNING TIME. SORTED LIST?
{
	//linear search for min dist
	if (l->getSize() != 0) {
		sf::Vector2f lPos = l->getFood(0).getPos();
		float n = getDist(lPos);
		int ind = 0;
		int i;
		for (i = 1; i <= l->getSize()-1; i++) {
			float temp = getDist(l->getFood(i).getPos());
			if (temp < n) {
				n = temp;
				ind = i;
			}
		}
		return ind;
	}

}

void Creature::draw(sf::RenderWindow *w)
{
	w->draw(m_creature);
}

float Creature::getDist(sf::Vector2f p) const
{
	sf::Vector2f pos = m_creature.getPosition();
	float x = (pos.x - p.x)*(pos.x - p.x);
	float y = (pos.y - p.y)*(pos.y - p.y);
	float res = sqrt(x + y);
	return res;

}

Creature Creature::reproduce()
{
	//Mutation factor: determines the magnitude of the mutation
	float mutation = rand() %11 + (-5);

	//eff to speed relationship is linear
	//SUBJECT TO CHANGE
	float s = speed + mutation/10;
	float e = eff + mutation/10;
	if (s > 0 && e > 0.2) { // Efficiency cannot be too low
		Creature baby(m_creature.getPosition(), s, e);
		return baby;
	}
	else {
		Creature baby(m_creature.getPosition(), speed, eff);
		return baby;
	}

}

float Creature::getEff()
{
	return eff;
}

float Creature::getSpeed()
{
	return speed;
}

int Creature::getXp()
{
	return m_xp;
}