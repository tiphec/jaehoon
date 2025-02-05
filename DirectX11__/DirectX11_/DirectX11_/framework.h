﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <memory>
#include <wrl/client.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#include "../DirectXTex/DirectXTex.h"

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

using namespace std;
using namespace DirectX;

// Framework
#include "Core/Device.h"
#include "Core/Render/VertexLayout.h"
#include "Core/Render/VertexBuffer.h"
#include "Core/Render/VertexShader.h"
#include "Core/Render/PixelShader.h"
#include "Core/Texture/SamplerState.h"
#include "Core/Texture/SRV.h"

// Matrix
#include "Core/Render/ConstantBuffer.h"
#include "Core/Render/BufferLayOut.h"

// Bagic Obj
#include "Contents/Quad.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"

extern HWND hWnd;

// Macro
#define DEVICE  Device::Instance()->GetDevice()
#define DC		Device::Instance()->GetDC()
#define RTV		Device::Instance()->GetRTV()

#define WIN_WIDTH	 1200
#define WIN_HEIGHT	 720