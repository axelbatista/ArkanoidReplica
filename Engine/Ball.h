#pragma once
#include "Vec2.h"
#include "Colors.h"

class Ball {
	Vec2 spot;
	int size;
	Color c;
	Vec2 direction;

public:
	Ball() : spot{ 410,515 }, size{ 5 }, c{ Colors::White }{};
	const Vec2& getSpot() const;
	const int getSize() const; 
	const Color& getColor() const;
	void setDir(float x);
	void move();
	const void isTouchingWall();
	void setDir(float x, float y);
};