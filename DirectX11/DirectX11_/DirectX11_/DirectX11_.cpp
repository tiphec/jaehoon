﻿// DirectX11_.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "DirectX11_.h"

#define MAX_LOADSTRING 100

// Direct X : Direct Access
// => 하드웨어에 직접 접근을 도와주는 API를 제공해준다 (GPU)

// CPU vs GPU
// - GPU는 연산장치의 개수가 CPU보다 월등하게 많다
// - GPU 연산장치는 단순한 계산 처리에 특화되어있다
// ==> CPU(교수님 한명) vs GPU(초등학생 만명)

// WIN_API => 픽셀찍어서 그리기 (DIrectX도 기본적으로 똑같다. 하지만 GPU가 대신해준다)
// 화면 해상도 : 1920 x 1080개수의 픽셀 계산을 CPU가 하는것이 효윻적인가?
// => 초등학생 1만명한테 맡기겠다

// DX2D => 게임엔진 만들기 (유니티같은거)
// 영화 촬영
// 총감독 / 프로그래머
// 영화사 / 게임엔진
// 세트장 / world
// 카메라 / 카메라
// 배우 / actor
// 조명 / light

// 렌더링파이프라인(3차원 가상에 있는 점들의 집합(매쉬)을 우리가 모니터(2차원)으로 어떻게 변환되는지에 대한 간계)

// com 객체
// -동적할당율 Create/Release

// 인력사무소장
// 외주를 맡기고 실질적인 공사 대표 뽑기
// 컴퓨터 하드웨어 기능 점검, 리소스 할당(하드웨어 접근에 필요한 리소스 할당)
Microsoft::WRL::ComPtr<ID3D11Device> device;

// 연출감독
// 세트장을 실질적으로 꾸며주는 연출가
// 렌더링 대상 결정(어따 그릴지, 얼마나 그릴지 결정)
// -> 리소스를 그래픽 파이프라인에 바인딩, GPU가 수행할 명령을 지시한다
Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

// 렌더링파이프라인 단계
Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
Microsoft::WRL::ComPtr<D3D11InputLayout> inputLayout;

// 텍스쳐 맵핑 : 판박이
Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> shaderResourceView; // SRV -> 판박이 만드는 아저씨
Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState; // sampler -> 판박이 붙이는 아저씨

HWND hWnd;

struct Vertex
{
    Vertex() {}
    Vertex(XMFLOAT3 pos) :

    XMFLOAT3 pos;
};

void InitDevice();
void Render();

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DIRECTX11, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DIRECTX11));

    InitDevice();

    MSG msg = {};

     while (msg.message != WM_QUIT)
    {
         if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
         {
             if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
             {
                 TranslateMessage(&msg);
                 DispatchMessage(&msg);
             }
         }
         else
         {
             // 최적화
             //메인루프
             Render();
         }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DIRECTX11));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DIRECTX11);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void InitDevice()
{
    RECT rc;
    GetClientRect(hWnd, &rc);
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,

    };

    UINT featureSize = ARRAYSIZE(featureLevels);

    DXGI_SWAP_CHAIN_DESC sd = {};
    sd.BufferCount = 1;
    sd.BufferDesc.with = with;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    // 화면 프레임 갱신 속도
    sd.BufferUsage = DXGI_USAGE;

    // 렌더링파이프라인

    D3D11_INPUT_ELEMENT_DESC layOut[] =
    {
        {
            "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0
            D3D11_INPUT_PER_VERTEX_DATA,0
        },
        {
            "UV",0,DXGI_FORMAT_R32G32_FLOAT,0,12 // POSITION SE
            DD3D11_INPIT_PER_VERTEX_DATA,0
        }
    };


    Micosoft::WRL::ComPtr<ID3Blob> pixelBlob;
    D3DCopmileFromFile(L"shader/TutoricalShader.hlsl", nullptr, nullptr,
        "VS", "vs_5_0", flags, 0, vertexBlob.GetAddressOOf(), nullptr;

    // 판박이 아저씨들
    // Texture 준비, Shader에 넘기는 작업
    ScratchImage image;
    wstring psth = L"Resource/Sample.png";
    LoadFromWICFile(path.c_str(), WWIC_FLAGS_NONE, nullptr, image);

    CreateShaderResourceView(device.Get(), image.GetImages(), image.GetImageCount(), image.GetMetadata(), 
    IN shaderResourceView.ReleaseAndGetAddressOf());

    D3D11_SAMPLER_DESC sampDesc = {};
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
}

void Render()
{
    // 바탕화면
    FLOAT myColorR = 0.0f;
    FLOAT myColorG = 0.0f;
    FLOAT myColorB = 0.0f;

    FLOAT clearColor[4] = { myColorR, myColorG, myColorB, 1.0f };

    deviceContext->ClearRenderTargetView(renderTargetView.Get(), clearColor);

    // IA : Input Assembler : 입력 병합
    deviceContext->IASetInputLayout(inputLayout.Get());

    UINT stride = sizeof(vertex);
    UINT offset = 0;
    deviceContext->IASetVertexBuffers(0, 1, vertexBuffer.GetAddressOf(), &stride, &offset);
    deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    deviceContext->PSSetShaderResource()
    deviceContext->PSSetSamplers(0, 1, samplerState.GetAddressOf());


    deviceContext->VSSetShader
}
