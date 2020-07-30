#include "Rectangle.h"

void Rectangulars::add(const Rectangs& part)
{
	recs.push_back(part);
}

std::vector<Rectangs> Rectangulars::getRecs() const
{
	return recs;
}

void Rectangulars::isTouchingRecs(Ball& ball) const
{
	int top = ball.getSpot().y - 5;
	int bound = ball.getSpot().x;
	int sideR = bound + 5;
	int sideL = bound - 5;
	int bottom = top + 10;
	int bound2 = top + 5;
	int n = 0;
	for (auto each : recs) {
		Vec2 spoto = each.getSpot();
		if (bound >= spoto.x && bound <= spoto.x + 40 && top == spoto.y + 20) {
			ball.setDir(1, -1);
			each.reduceHealth();
			
		}
		else if (sideL == spoto.x + 40 && bound2 >= spoto.y && bound2 <= spoto.y + 20) {
			ball.setDir(-1, 1);
			each.reduceHealth();
		}
		else if (bottom == spoto.y && bound >= spoto.x && bound <= spoto.x + 40) {
			ball.setDir(1, -1);
			each.reduceHealth();
		}
		else if (sideR == spoto.x && bound2 >= spoto.y && bound2 <= spoto.y + 20) {
			ball.setDir(-1, 1);
			each.reduceHealth();
		}
	}
}

void Rectangulars::getRid(int n)
{
	recs.erase(recs.begin() + n);
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
