#include "Colliding.h"

const bool Colliding::isTouching(const Ball& ball, const Paddle& paddle)
{
    if (ball.getSpot().x >= paddle.getSpot().x && ball.getSpot().x <= paddle.getSpot().x + 60 && ball.getSpot().y + 5 == paddle.getSpot().y)
        return true;
    return false;
}

const void Colliding::applyBall(Ball& ball, const Paddle& paddle)
{
        if (ball.getSpot().x >= paddle.getSpot().x + 30) {
            ball.setDir(5.0f);
        } else {
            ball.setDir(-5.0f);
        }

}
