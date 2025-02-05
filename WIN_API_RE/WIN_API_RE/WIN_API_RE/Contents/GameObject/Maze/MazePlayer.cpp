#include "framework.h"
#include "MazePlayer.h"

MazePlayer::MazePlayer()
{
}

MazePlayer::~MazePlayer()
{
}

void MazePlayer::SetMaze(shared_ptr<Maze> maze)
{
    _maze = maze;
}

void MazePlayer::Init()
{
    _pos = { 0,0 };
    _pathIndex = 0;
    _time = 0.0f;
    _dir = Dir::UP;
    _path.clear();

    if (_maze != nullptr)
    {
         // _startPos = _maze ->
    }
}

void MazePlayer::RIghtHand()
{
}

bool MazePlayer::CanGo(int y, int x)
{
    return false;
}
