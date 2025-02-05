#pragma once
class Maze;

class MazePlayer
{
public:
	enum Dir
	{
		UP,
		LEFT,
		DOWN,
		RIGHT,

		RIT_COUNT = 4
	};

	MazePlayer();
	~MazePlayer();

	void SetMaze(shared_ptr<Maze> maze);
	void Init();

	void RIghtHand();

	bool CanGo(int y, int x);

private:
	shared_ptr<Maze> _maze;

	Dir _dir = Dir::UP;
	Vector _pos = { 1,1 };
	Vector _startPos = {};
	Vector _endPos = {};

	int _pathIndex = 0;
	float _time = 0.0f;

	vector<Vector> _path; // ã�� �濡 ���� ����
};

