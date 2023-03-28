#include "OperationMenuWindow.h"

using namespace std;

#define IDC_PROFILE_OM      1001
#define IDC_EXIT_OM         1002
#define IDC_GETBALANCE_OM   1003
#define IDC_TAKEBILLS_OM    1004
#define IDC_PUTBILLS_OM     1005

static const wchar_t CLASS_NAME[] = L"Окно снятия денег";

OperationMenuWindow::OperationMenuWindow() {
    static const wchar_t CLASS_NAME[] = L"Меню банкомата";
}

OperationMenuWindow::OperationMenuWindow(HINSTANCE hInstance) : hInstanceOM(hInstance) {
    static const wchar_t CLASS_NAME[] = L"Меню банкомата";
}

HWND OperationMenuWindow::Create() {
    WNDCLASS window = {};
    window.lpfnWndProc = WndProc;
    window.hInstance = hInstanceOM;
    window.lpszClassName = CLASS_NAME;

    RegisterClass(&window);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Банкомат",
        WS_OVERLAPPED | WS_VISIBLE,
        835, 315, 250, 450,
        NULL,
        NULL,
        hInstanceOM,
        NULL
    );

    hwndOM = hwnd;
    return hwndOM;
}

OperationMenuWindow::~OperationMenuWindow(){
    DestroyWindow(hwndOM);
}

LRESULT CALLBACK OperationMenuWindow::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
