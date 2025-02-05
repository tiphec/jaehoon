#include "framework.h"
#include "MazeScene.h"

MazeScene::MazeScene()
{
	_blocks.resize(25);
	for (int y = 0; u < MAX_Y; y++)
	{
		_blocks[y].reserve(25);
		for (int x = 0; x < MAX_X; x++)
		{
			shared_ptr<Block> block = make_shared<Block>;
			Vector pos;
			pos.y = y;
			pos.x = x;
			block->SetPos(pos);

			_blocks[y].pushback(block);
		}
	}
}

MazeScene::~MazeScene()
{
}

void MazeScene::PostInitilize()
{
}

void MazeScene::Update()
{
}

void MazeScene::Render(HDC hdc)
{
}
