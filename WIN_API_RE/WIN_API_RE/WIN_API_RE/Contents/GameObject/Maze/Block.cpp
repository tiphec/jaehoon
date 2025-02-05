#include "framework.h"
#include "Block.h"

Block::Block()
{
	_rect = make_shared<RectCollider>(Vector(300, 300), Vector(12, 12));
}

Block::~Block()
{
}

void Block::Update()
{
}

void Block::Render()
{
	SelectObject();
}
