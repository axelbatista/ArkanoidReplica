#include "Ball.h"

const Vec2& Ball::getSpot() const
{
    return spot;
}

const int Ball::getSize() const
{
    return size;
}

const Color& Ball::getColor() const
{
    return c;
}

void Ball::setDir(float x)
{
    direction = { x,-5.0f };
    move();
}

void Ball::setDir(float x, float y) {
    direction.x *= x;
    direction.y *= y;
}

const bool Ball::isStarted() const
{
    return ignited;
}

void Ball::setState()
{
    ignited = true;
}

void Ball::move()
{
    spot.x += direction.x;
    spot.y += direction.y;
}

const void Ball::isTouchingWall()
{
    if (spot.x + 5 >= 795 || spot.x - 5 <= 5)               //magic values but they are essentially the dimensions for the window - 5.
        direction.x *= -1;
    else if (spot.y - 5 <= 5 || spot.y + 5 >= 595)
        direction.y *= -1;
}
