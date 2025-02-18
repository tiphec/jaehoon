#pragma once
class TimeManager
{
	TimeManager();
	~TimeManager();
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new TimeManager();
	}
	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}
	static TimeManager* instance() { return _instance; }

	void Update();
	void SetLockFPS(double value) { _lockFPS = value; }

	int GetFPS();

private:
	static TimeManager* _instance;

	double _timeScale = 0.0f;
	double _deltaTime = 0.0f;

	unsigned __int64 _curTime = 0;
	unsigned __int64 _lastTime = 0;
	unsigned __int64 _periodFrequency = 0; // 초당 cpu 진동수

	unsigned int _frameRate = 0;
	unsigned int _frameCount = 0;

	double _oneSceCount = 0.0f;
	double _runTime = 0.0;
	double _lockFPS = 0.0;
};

