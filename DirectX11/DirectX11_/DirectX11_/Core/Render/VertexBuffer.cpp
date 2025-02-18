#include "framework.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(void* data, UINT count, UINT stride, UINT offset)
{
    _data = data;
    _count = count;
    _stride = stride;
    _offset = offset;

	CreateVertexBuffer();
}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::SetVertexBuffer(UINT slot)
{
    DC->IASetVertexBuffers(0, 1, vertexBuffer.GetAddressOf(), &_stride, &_offset);
}

void VertexBuffer::CreateVertexBuffer()
{
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = _stride * _count;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = _data;

    DEVICE->CreateBuffer(&bd, &initData, vertexBuffer.GetAddressOf());
}
