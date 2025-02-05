#include "framework.h"
#include "program.h"

#include "Scenes/CollisionScene.h"
#include "Scenes/PaintScene.h"
#include "Scenes/LineScene.h"
#include "Scenes/MazeScene.h"

Program::Program()
{
	//_sceneTable["PaintScene"] = make_shared<PaintScene>();
	_sceneTable["CollisionScene"] = make_shared<CollisionScene>();
	_sceneTable["LineScene"] = make_shared<LineScene>();
	_sceneTable["MazeScene"] = make_shared<MazeScene>();

	_curScene = "MazeScene";
}

Program::~Program()
{
}

void Program::Update()
{
	_sceneTable[_curScene]->Update();
}

void Program::Render(HDC hdc)
{
	_sceneTable[_curScene]->Render(hdc);
}