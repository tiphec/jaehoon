#include "framework.h"
#include "RectCollider.h"


RectCollider::RectCollider(Vector center, Vector size)
{
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
}

bool RectCollider::IsCollision(const Vector& pos) const
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<class RectCollider> other) const
{
	
}