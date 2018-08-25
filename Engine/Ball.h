#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	enum WallCollisionResult
	{
		NoCollision,
		WallCollision,
		BottomCollision
	};
public:
	Ball(const Vec2& in_pos, const Vec2& in_dir);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	WallCollisionResult DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
	void SetDirection(const Vec2& dir);
private:
	static constexpr float radius = 7.0f;
	float speed = 400.0f;
	Vec2 pos;
	Vec2 vel;
};