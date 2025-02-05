#pragma once

class Block
{
public:
	Block();
	~Block();

	void Update();
	void Render();


private:
	shared_ptr<maze> _maze;
};