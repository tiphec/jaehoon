#pragma once
class CircleCollider
{
public:
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	void Update();
	void Render();

private:
	Vector _center;
	float _radius;
};

