#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include <vector>
#include "Rectangle.h"

class Board {
	static constexpr int width = 40;
	static constexpr int height = 20;
	static constexpr int howManyX = Graphics::ScreenWidth / width;
	static constexpr int howManyY = 18;
	std::vector<Rectangs> space;
	int size;

public:
	Board();
	Rectangs chooseRandom();
	void removeVec();
};