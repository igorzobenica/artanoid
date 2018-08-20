#pragma once

#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float in_left, float in_top, float in_right, float in_bottom);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool isOverLappingWith(const RectF& other) const;

private:
	float left;
	float top;
	float right;
	float bottom;
};
