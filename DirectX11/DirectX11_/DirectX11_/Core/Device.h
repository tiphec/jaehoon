#pragma once
class Device
{
public:
	static void Create()
	{
		if (_instance != nullptr)
		{

		}
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Device* Instance()
	{
		return _instance;
	}

private:
	Device();
	~Device();

	static Device* _instance;

	Microsoft::WRL::ComPtr<ID3D11Device>		_device;
	Microsoft::WRL::ComPtr<ID3D11Device>		_deviceContext;
	Microsoft::WRL::ComPtr<IDXGISwapChain>		_swapChain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _renderTargetView;


};