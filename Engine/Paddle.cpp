#include "Paddle.h"

Paddle::Paddle(const Vec2 & pos_in, float halfWidth_in, float halfHeight_in)
	:
	pos(pos_in),
	halfWidth(halfWidth_in),
	halfHeight(halfHeight_in)
{
}

void Paddle::Draw(Graphics & gfx) const
{
	gfx.DrawRect(GetRect(), color);
}

bool Paddle::DoBallCollision(Ball & ball) const
{
	if (GetRect().isOverLappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF & walls) const
{
}

void Paddle::Update(const Keyboard & kbd, float dt)
{
}

RectF Paddle::GetRect() const
{
	return RectF();
}
