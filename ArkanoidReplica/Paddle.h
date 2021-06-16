#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "MainWindow.h"


class Paddle {
	Vec2 spot;
	Vec2 center;
	Color c;
	int x;

public:
	static constexpr int width = 60;
	static constexpr int height = 10;
	Paddle() : spot{ 380,520 }, c{ Colors::Red }, center{ 410,520 } {}
	void move(const Mouse& mouse);
	const Vec2 getSpot() const;
	const Color getColor() const;
	void draw(Graphics& gfx);
};
