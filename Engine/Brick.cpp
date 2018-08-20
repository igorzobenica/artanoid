#include "Brick.h"

Brick::Brick(const RectF & in_rect, const Color & c)
	:
	rect(in_rect),
	color(c)
{
}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, color);
}
