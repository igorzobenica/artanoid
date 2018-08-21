#pragma once

#include "Ball.h"
#include "Brick.h"
#include "RectF.h"
#include "Graphics.h"
#include "Colors.h"
#include "Keyboard.h"


class Paddle
{
public:
	Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const RectF& walls) const;
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
private:
	Color color = Colors::White;
	float speed = 300.0f;
	float halfWidth;
	float halfHeight;
	Vec2 pos;
};