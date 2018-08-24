#include "Walls.h"
#include <assert.h>

Walls::Walls(const RectF innerBounds_in, float thickness_in, Color baseColor)
	:
	innerBounds(innerBounds_in),
	thickness(thickness_in),
	bev(baseColor)
{
	// make sure the tickness divides evenly into 2 for layout purposes
	assert(int(thickness) % 2 == 0);
	assert(innerBounds.GetExpanded(thickness).IsContainedBy(Graphics::GetScreenRect()));
}

const RectF & Walls::GetInnerBounds() const
{
	return innerBounds;
}

void Walls::Draw(Graphics & gfx) const
{
	// divide thickness by two because the value passed in the thickness used for the inner bevel and the outher bevel
	bev.DrawBevelFrame(innerBounds.GetExpanded(thickness), int(thickness) / 2, gfx);
}
