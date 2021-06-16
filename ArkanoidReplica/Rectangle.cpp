#include "Rectangle.h"

Rectangulars::Rectangulars()
{
	std::uniform_int_distribution<int> pick(1, 10);
	for (int i = 0; i < howManyX; i++) {
		for (int j = 2; j < howManyY; j++) {				//we're picking rectangles within a region by iterating through two for loops.
			if (pick(mt) < 4)								//choosing where to place the rectangles within those bounds is handled by a random value.
			recs.push_back(Rectangs(i * width, j * height));
		}
	}
}

void Rectangulars::draw(Graphics& gfx)
{
	for (const Rectangs& each : recs) {
		gfx.DrawRect(each.getSpot().x, each.getSpot().y, each.getSpot().x + 38, each.getSpot().y + 18, each.getColor());
	}
}

bool Rectangulars::isTouchingRecs(Ball& ball) 
{
	bool start = false;
	int boundx = ball.getSpot().x;
	int boundy = ball.getSpot().y;
	for (int i = 0; i < recs.size(); i++) {
		Vec2 spoto = recs[i].getSpot();
		if (boundx >= spoto.x && boundx <= spoto.x + 40 && boundy <= spoto.y + 20 && boundy >= spoto.y + 16) {			//this is the main work for the game.
			ball.setDir(1, -1);																					//instead of doing something comprehensive and checking for the entire shape of the ball.
			recs[i].reduceHealth();																				//we simply check on four critical areas (leftmost, topmost, rightmost, bottomost).
			start = true;																						//while I had problems initially, this proved to be sufficient as there is no phasing of the ball into or through rectangles,
		}																										//with it neither going through little corners.
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
		if (recs[i].getHealth() == 0) {
			Rectangs hold = recs[i];
			recs[i] = recs[recs.size() - 1];								//big size array where we could do .erase, but because the order for the rectangles doesn't matter.
			recs[recs.size() - 1] = hold;									//I simply did a std::swap for towards the back and then did a popback for a quick O(1) operation.
			recs.pop_back();
		}
	}
	return start;
}

const Vec2& Rectangs::getSpot() const
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
