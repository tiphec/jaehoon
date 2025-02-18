#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring path)
{
    CreateVertices();

	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), _vertices.size(), sizeof(Vertex_Texture));
    _indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());

	_vs = make_shared<VertexShader>(L"Shader/TextureVertexShader.hlsl");
	_ps = make_shared<PixelShader>(L"Shader/TexturePixelShader.hlsl");
	_srv = make_shared<SRV>(path);

    _transform = make_shared<Transform>();
}

Quad::~Quad()
{
}

void Quad::Update()
{
    _transform->Update();
}

void Quad::Render()
{
    _vs->SetInputLayout();
    _vertexBuffer->SetVertexBuffer(0);
    _indexBuffer->IASetIndexBuffer();

    _srv->PSSet(0);
    SAMPLER->PSSet(0);

    _transform->SetVSSlot(0);

    _vs->SetShader();
    _ps->SetShader();

    DC->DrawIndexed(_indices.size(), 0,0);
}

void Quad::CreateVertices()
{
    Vertex_Texture temp;
    temp.pos = XMFLOAT3(-300.0f, 300.0f, 0.0f);
    temp.uv = XMFLOAT2(0, 0);
    _vertices.push_back(temp); // ���� ��

    temp.pos = XMFLOAT3(300.0f, -300.0f, 0.0f);
    temp.uv = XMFLOAT2(1, 1);
    _vertices.push_back(temp); // ������ �Ʒ�

    temp.pos = XMFLOAT3(-300.0f, -300.0f, 0.0f);
    temp.uv = XMFLOAT2(0, 1);
    _vertices.push_back(temp); // ���� �Ʒ�

    temp.pos = XMFLOAT3(300.0f, 300.0f, 0.0f);
    temp.uv = XMFLOAT2(1, 0);
    _vertices.push_back(temp); // ������ ��

    // 031 012
    _indices.push_back(0);
    _indices.push_back(3);
    _indices.push_back(1);
    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);
}
