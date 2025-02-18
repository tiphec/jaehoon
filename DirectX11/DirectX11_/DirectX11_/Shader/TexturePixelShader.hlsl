
Texture2D map : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
};


// �� �ȼ����� ���Ǵ� ����
float4 PS(PixelInput input) : SV_TARGET
{
    return map.Sample(samp, input.uv);

}