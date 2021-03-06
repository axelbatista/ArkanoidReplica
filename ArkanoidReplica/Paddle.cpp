#include "Paddle.h"


void Paddle::move(const Mouse& mouse)
{	
	x = spot.x;
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

void Paddle::draw(Graphics& gfx)
{
	gfx.DrawRect(spot.x, spot.y, spot.x + Paddle::width, spot.y + Paddle::height, c);
}
