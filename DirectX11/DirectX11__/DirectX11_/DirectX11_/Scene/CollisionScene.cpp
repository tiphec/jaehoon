#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circleCollider = make_shared<CircleCollider>(CENTER, 100);
	_rectCollider = make_shared<_rectCollider>(CENTER - Vector(0, 100), Vector(100, 100);
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_circleCollider->Update();
	_rectCollider->Update();
}

void CollisionScene::Render()
{
	_circleCollider
}

void CollisionScene::Input()
{

}
