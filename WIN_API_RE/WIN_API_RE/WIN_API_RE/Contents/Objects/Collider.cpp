#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
	_colors[0];
}

Collider::~Collider()
{
}

bool Collider::IsCollision(shared_ptr<Collider> collider) const
{
	switch (collider->_type)
	{
	case Collider::NONE:
		return false;
	case Collider::CIRCLE:
	{
		shared_ptr<CircleCollider>circle = dynamic_pointer_cast<CircleCollider>(collider);
		return IsCollision(circle);
	}
	case Collider::RECT:
	{
		shared_ptr<RectCollider>rect = dynamic_pointer_cast<RectCollider>(collider);
		return IsCollision(rect);
	}
	default:
		break;
	}





	return false;
}