#include "Brick.h"

Brick::Brick(const RectF & in_rect, const Color & c)
	:
	rect(in_rect),
	color(c)
{
}

void Brick::Draw(Graphics & gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(rect, color);
	}
}

bool Brick::DoBallCollision(Ball & ball)
{
	if (!destroyed && rect.isOverLappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}
