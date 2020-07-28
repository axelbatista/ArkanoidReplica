#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "MainWindow.h"


class Paddle {
	Vec2 spot;
	Color c;
public:
	static constexpr int width = 60;
	static constexpr int height = 10;
	Paddle() : spot{ 380,520 }, c{255,0,255} {}
	void move(const MainWindow& mouse);
	const Vec2 getSpot() const;
	const Color getColor() const;
};
