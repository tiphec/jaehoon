#pragma once

class MatrixBuffer : public ConstantsBuffer
{
public:
	struct Data
	{
		XMMATRIX matrix = XMMatrixIdentity();
	};

	MatrixBuffer
		:ConstantBuffer(&_data, sizeof(Data))
	{

	}
	~MatrixBuffer() {}

	void SetData(XMMATRTIX value)
	{
		data.matrix = XMMatrix
	}

private:
	Data _data;
};