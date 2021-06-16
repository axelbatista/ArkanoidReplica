#pragma once
#include "Vec2.h"
#include <vector>
#include "Colors.h"
#include <random>
#include "Ball.h"
#include "Graphics.h"
#include <ctime>

static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

class Rectangs {
	Vec2 spot;
	Color c;
	int health;
public:
	Rectangs(int one, int two) : spot{ one,two }, health{ 3 } {
		std::uniform_int_distribution<int> choice(20, 255);
		unsigned char p = static_cast<unsigned char>(choice(mt));
		unsigned char q = static_cast<unsigned char>(choice(mt));				//so that each rectangle can have a random color
		unsigned char z = static_cast<unsigned char>(choice(mt));
		c = { p,q,z };
	}
	const Vec2& getSpot() const;
	const Color& getColor() const;
	void reduceHealth();
	const int getHealth() const;
};


class Rectangulars {
	std::vector<Rectangs> recs;
	static constexpr int width = 40;
	static constexpr int height = 20;
	static constexpr int howManyX = Graphics::ScreenWidth / width;
	static constexpr int howManyY = 15;
public:
	Rectangulars();
	void draw(Graphics& gfx);
	bool isTouchingRecs(Ball& ball);

};