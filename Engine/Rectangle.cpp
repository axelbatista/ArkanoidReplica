#include "Rectangle.h"

void Rectangulars::add(const Rectangs& part)
{
	recs.emplace_back(part);
}

std::vector<Rectangs> Rectangulars::getRecs() const
{
	return recs;
}

bool Rectangulars::isTouchingRecs(Ball& ball) 
{
	bool start = false;
	int boundx = ball.getSpot().x;
	int boundy = ball.getSpot().y;
	for (int i = 0; i < recs.size(); i++) {
		Vec2 spoto = recs[i].getSpot();
		if (boundx >= spoto.x && boundx <= spoto.x + 40 && boundy <= spoto.y + 20 && boundy >= spoto.y + 16) {
			ball.setDir(1, -1);
			recs[i].reduceHealth();
			start = true;
		}
		else if (boundx >= spoto.x + 36 && boundx <= spoto.x + 40 && boundy >= spoto.y && boundy <= spoto.y + 20) {
			ball.setDir(-1, 1);
			recs[i].reduceHealth();
			start = true;
		}
		else if (boundy <= spoto.y + 4 && boundy >= spoto.y && boundx >= spoto.x && boundx <= spoto.x + 40) {
			ball.setDir(1, -1);
			recs[i].reduceHealth();
			start = true;
		}
		else if (boundx <= spoto.x + 4 && boundx >= spoto.x && boundy >= spoto.y && boundy <= spoto.y + 20) {
			ball.setDir(-1, 1);
			recs[i].reduceHealth();
			start = true;
		}
		if (recs[i].getHealth() == 0)
			recs.erase(recs.begin() + i);
	}
	return start;
}

Vec2 Rectangs::getSpot() const
{
	return spot;
}

const Color& Rectangs::getColor() const
{
	return c;
}

void Rectangs::reduceHealth()
{
	health--;
}

const int Rectangs::getHealth() const
{
	return health;
}
