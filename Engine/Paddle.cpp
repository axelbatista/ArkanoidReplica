#include "Paddle.h"


void Paddle::move(const MainWindow& wnd)
{
	if (wnd.mouse.IsInWindow()) {
		if (spot.x + wnd.mouse.GetPosX() < 0)
			spot.x == 0;
		else if (spot.x + wnd.mouse.GetPosX() > 740)
			spot.x == 739;
		spot.x += wnd.mouse.GetPosX();
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
