#pragma once
class PaintScene
{
public:

private:
	int _curColor = 0;

	vector<HPEN> _pens;
	vector<HBRUSH> _brushes;

	shared_ptr<CircleCollider> myCircle = make_shared<CircleCollider>(Vector(200, 200), 70);
};

