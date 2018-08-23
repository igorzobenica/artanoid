#include "Brick.h"
#include <assert.h>

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
		gfx.DrawRect(rect.GetExpanded(- padding), color);
	}
}

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return !destroyed && rect.isOverLappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball & ball)
{
	assert(CheckBallCollision(ball));

	const Vec2 ballPos = ball.GetPosition();
	if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
