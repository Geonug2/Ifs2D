#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <iostream>
#include <wrl.h> // Microsoft::WRL::ComPtr

using Microsoft::WRL::ComPtr;

// Akna suurus
const int WINDOW_WIDTH = 1366;
const int WINDOW_HEIGHT = 768;

// Akna protseduur
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Peamine funktsioon
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nShowCmd) {
    // Akna klass
    const wchar_t CLASS_NAME[] = L"InfinitySpaceClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Loo aken
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Infinity Space", // Unicode string
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nShowCmd);

    // DirectX 12 algus
    UINT dxgiFactoryFlags = 0;
    ComPtr<IDXGIFactory4> factory;
    CreateDXGIFactory1(IID_PPV_ARGS(&factory));

    // Oota akna sulgemist
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}