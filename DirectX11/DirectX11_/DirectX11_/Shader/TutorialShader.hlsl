
Texture2D map : register(t0);
SamplerState samp : register(s0);


// SV : 시스템벨류
// semantic : 의미

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
    // 계산
    PixelInput output;
    output.pos = input.pos;
    output.uv = input.pos;
    
    return pos;
}

// 각 픽셀마다 계산되는 공식
float4 PS() : SV_TARGET
{
    return float4(1.0f, 1.0f, 1.0f, 1.0f);
}

// 각 픽셀마다 계산되는 공식
float3 PS(PixelInput input) : SV_TARGET
{
    return map.Sample(samp, input.uv);

}