#pragma once
class BowScene : public Scene
{
public:
	BowScene();
	~BowScene();

	void Fire();

	void Update() override;
	void Render() override;

};

