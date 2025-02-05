#pragma once
class CannonScene
{
public:
	CannonScene();
	~CannonScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<class Cannon> _cannon;
};

