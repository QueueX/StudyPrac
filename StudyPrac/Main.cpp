#include <Windows.h>
#include <string>
#include "TakeBillsWindow.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    TakeBillsWindow takeBillsWindow(hInstance);
    HWND hwnd = takeBillsWindow.Create();

    if (hwnd == NULL) {
        return 0;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ShowWindow(hwnd, nCmdShow);

    return static_cast<int>(msg.wParam);
}