#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const Vec2& in_pos, const Vec2& in_vel);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};