#pragma once
#include "Ball.h"
#include "Paddle.h"


class Colliding {
public:
	const static bool isTouching(const Ball& ball, const Paddle& paddle);
	const static void applyBall(Ball& ball, const Paddle& paddle);
};