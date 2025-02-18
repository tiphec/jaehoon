#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circleCollider1 = make_shared<CircleCollider>(CENTER, 100);
	_circleCollider2 = make_shared<CircleCollider>(Vector(250,0), 50);
	_circleCollider3 = make_shared<CircleCollider>(CENTER - Vector(250,0), 100);
	_rectCollider = make_shared<RectCollider>(Vector(100,100), Vector(100, 100));


	_rectCollider->GetTransform()->SetParent(_circleCollider1->GetTransform());

	// circle1,2 �����, �� circle2�� ���� ��Ų ���¿��� circle1 �̵� �� ȸ��
	// extra... circle3
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_circleCollider1->Update();
	_circleCollider2->Update();
	_circleCollider3->Update();
	_rectCollider->Update();

	Input();

	if(_rectCollider->IsCollision(mousePos))
		_rectCollider->SetRed();
	else
		_rectCollider->SetGreen();
}

void CollisionScene::Render()
{
	_circleCollider1->Render();
	_circleCollider2->Render();
	_circleCollider3->Render();
	_rectCollider->Render();
}

void CollisionScene::Input()
{
	if (KEY_PRESS('W'))
	{
		_circleCollider1->GetTransform()->AddScale(Vector(0.001f, 0.001f));
		//_rectCollider->GetTransform()->AddScale(Vector(0.001f, 0.001f));
	}

	if (KEY_PRESS('S'))
	{
		_circleCollider1->GetTransform()->AddScale(Vector(-0.001f, -0.001f));
		//_rectCollider->GetTransform()->AddScale(Vector(-0.001f, -0.001f));
	}

	if (KEY_PRESS('A'))
	{
		_circleCollider1->GetTransform()->AddAngle(0.001f);
	}

	if (KEY_PRESS('D'))
	{
		_circleCollider1->GetTransform()->AddAngle(-0.001f);
	}
}
