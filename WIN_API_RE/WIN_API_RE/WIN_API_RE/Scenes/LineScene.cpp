#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector(100, 100), Vector(0, 0));
	_line2 = make_shared<Line>(Vector(100, 500), Vector(1280, 500));
	_line3 = make_shared <Line> (Vector(100, 400), Vector(150, 400));
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_line1->_end = mousePos;

	_line1->Update();
	_line2->Update();
	_line3->Update();

	// line2의 단위벡터 구하기
	Vector line2Normal = (_line2->_end - _line2->_start).NormalVector();
	// line1의 벡터 구하기
	Vector line1V = (_line1->_end - _line1->_start)
	// 내적시키기 (Dot Product)
	Vector length = _line1
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
}
