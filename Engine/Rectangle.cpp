#include "Rectangle.h"

void Rectangulars::add(const Rectangs& part)
{
	recs.push_back(part);
}

std::vector<Rectangs> Rectangulars::getRecs() const
{
	return recs;
}

Vec2 Rectangs::getSpot() const
{
	return spot;
}

const Color& Rectangs::getColor() const
{
	return c;
}
