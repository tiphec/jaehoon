#pragma once
class cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	void PostInitilize() { Ready();}
	void update();
	void Render(HDC hdc);

	const Vector& GetCenter() { return _body->Center(); }

	void Fire();

	bool IsFireReady()
	{
		_fireTime += 0.01f;
		if (_fireTime > _fireDelay)
		{
			_fireTime = 0.0f;
			return true;

		}
		return false
	}




private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<class Barrel> _barrel;

};

