#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& in_rect, const Color& c);
	void Draw(Graphics& gfx) const;
private:
	RectF rect;
	Color color;
	bool destroyed = false;
};
