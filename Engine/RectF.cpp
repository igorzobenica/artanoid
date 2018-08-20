#include "RectF.h"

RectF::RectF(float in_left, float in_top, float in_right, float in_bottom)
	:
	left(in_left),
	right(in_right),
	top(in_top),
	bottom(in_bottom)
{
}

RectF::RectF(const Vec2 & topLeft, const Vec2 & bottomRight)
	:
	RectF(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y)
{
}

RectF::RectF(const Vec2 & topLeft, float width, float height)
	:
	RectF(topLeft, topLeft + Vec2(width, height))
{
}

bool RectF::isOverLappingWith(const RectF & other) const
{
	return right > other.left && left < other.right && bottom > other.top && top < other.bottom;
}