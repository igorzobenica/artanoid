#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2 & in_pos, const Vec2 & in_dir)
	:
	pos(in_pos)
{
	SetDirection(in_dir);
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

Ball::WallCollisionResult Ball::DoWallCollision(const RectF & walls)
{
	WallCollisionResult collisionResult = WallCollisionResult::None;
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x +=  walls.left - rect.left;
		ReboundX();
		collisionResult = WallCollisionResult::SideTop;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		collisionResult = WallCollisionResult::SideTop;
	}
	if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collisionResult = WallCollisionResult::SideTop;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collisionResult = WallCollisionResult::Bottom;
	}
	return collisionResult;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

Vec2 Ball::GetPosition() const
{
	return pos;
}

void Ball::SetDirection(const Vec2 & dir)
{
	vel = dir.GetNormalized() * speed;
}
