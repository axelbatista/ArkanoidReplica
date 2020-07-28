#pragma once
#include "Vec2.h"
#include <vector>
#include "Colors.h"
#include <random>

namespace randol {
	extern std::mt19937 mt;
}

class Rectangs {
	Vec2 spot;
	Color c;
public:
	Rectangs(int one, int two) : spot{ one,two } {
		std::uniform_int_distribution<int> choice(20, 255);
		unsigned char p = static_cast<unsigned char>(choice(randol::mt));
		unsigned char q = static_cast<unsigned char>(choice(randol::mt));
		unsigned char z = static_cast<unsigned char>(choice(randol::mt));
		c = { p,q,z };
	}
	Vec2 getSpot() const;
	const Color& getColor() const;

};


class Rectangulars {
	std::vector<Rectangs> recs;
public:
	Rectangulars() {}
	void add(const Rectangs& part);
	std::vector<Rectangs> getRecs() const;

};