#include "Paddle.h"


void Paddle::move(const Mouse& mouse)
{	
	if (mouse.GetPosX() < 30) {
		center.x = 30;
		spot.x = center.x - 30;
	}
	else if (mouse.GetPosX() > 770) {
		center.x = 770;
		spot.x = center.x - 30;
	} else {
		center.x = mouse.GetPosX();
		spot.x = center.x - 30;
	}
}

const Vec2 Paddle::getSpot() const
{
	return spot;
}

const Color Paddle::getColor() const
{
	return c;
}
