
Texture2D map : register(t0);
SamplerState samp : register(s0);


// SV : �ý��ۺ���
// semantic : �ǹ�

struct VertexInput
{
    float4 pos : POSITIONT;
    float2 uv : UV;
};

struct PinxelInput
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
};

float VS(VertexInput input)
{
    // ���
    PixelInput output;
    output.pos = input.pos;
    output.uv = input.pos;
    
    return pos;
}

// �� �ȼ����� ���Ǵ� ����
float4 PS() : SV_TARGET
{
    return float4(1.0f, 1.0f, 1.0f, 1.0f);
}

// �� �ȼ����� ���Ǵ� ����
float3 PS(PixelInput input) : SV_TARGET
{
    return map.Sample(samp, input.uv);

}