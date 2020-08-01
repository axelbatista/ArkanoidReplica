#include "Board.h"
#include <random>
#include <ctime>
#include "Rectangle.h"

 namespace randol {
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

Board::Board()
{
	for (int i = 0; i < howManyX; i++) {
		for (int j = 2; j < howManyY; j++) {
			space.emplace_back(Rectangs(i * width, j * height));
		}
	}
	size = space.size();
}

Rectangs Board::chooseRandom()
{
	std::uniform_int_distribution<int> choice(0, size-1);
	size--;
	int rand = choice(randol::mt);
	space.erase(space.begin() + rand);
	return space.at(rand);
}

void Board::removeVec()
{
	space.clear();
}

