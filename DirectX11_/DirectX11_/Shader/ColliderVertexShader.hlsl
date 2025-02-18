cbuffer World : register(b0)
{
    matrix world;
}

cbuffer View : register(b1)
{
    matrix view;
}

cbuffer Projection : register(b2)
{
    matrix projection;
}

struct VertexInput
{
    float4 pos : POSITION;
};

struct VertexOuput
{
    float4 pos : SV_POSITION;
};

VertexOuput VS(VertexInput input)
{
    // �� ������ ���ؼ� �ʿ��� ���
    VertexOuput output;
    output.pos = input.pos;
    output.pos = mul(output.pos, world);
    output.pos = mul(output.pos, view);
    output.pos = mul(output.pos, projection);
    
    return output;
}