#pragma once
class MazeScene : public Scene
{
public:
	MazeScene();
	~MazeScene();

	void PostInitilize();
	void Update();
	void Render(HDC hdc);

private:

};

