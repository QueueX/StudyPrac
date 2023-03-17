#include "TakeBillsWindow.h"

using namespace std;

static const wchar_t CLASS_NAME[] = L"Окно снятия денег";


TakeBillsWindow::TakeBillsWindow(HINSTANCE hInstance) : hInstanceTB(hInstance) {
    static const wchar_t CLASS_NAME[] = L"Окно снятия денег";
}


#define IDC_ENTER_TB 1001
#define IDC_CLEAR_TB 1002
#define IDC_CLOSE_TB 1003


HWND TakeBillsWindow::Create() {
    WNDCLASS window = {};
    window.lpfnWndProc = WndProc;
    window.hInstance = hInstanceTB;
    window.lpszClassName = CLASS_NAME;

    RegisterClass(&window);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Снять деньги",
        WS_OVERLAPPED | WS_VISIBLE,
        835, 315, 250, 450,
        NULL,
        NULL,
        hInstanceTB,
        NULL
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    inputTB = CreateWindowEx(
        0,
        L"EDIT",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
        10, 10, 100, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    enterTB = CreateWindowEx(
        0,
        L"BUTTON",
        L"Снять",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        120, 10, 100, 30,
        hwnd,
        (HMENU) IDC_ENTER_TB,
        hInstanceTB,
        NULL
    );

    HWND text5000 = CreateWindowEx(
        0,
        L"STATIC",
        L"5000:",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        10, 50, 50, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    bill5000TB = CreateWindowEx(
        0,
        L"STATIC",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
        70, 50, 150, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    HWND text2000 = CreateWindowEx(
        0,
        L"STATIC",
        L"2000:",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        10, 90, 50, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    bill2000TB = CreateWindowEx(
        0,
        L"STATIC",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
        70, 90, 150, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    HWND text1000 = CreateWindowEx(
        0,
        L"STATIC",
        L"1000:",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        10, 130, 50, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    bill1000TB = CreateWindowEx(
        0,
        L"STATIC",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
        70, 130, 150, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    HWND text500 = CreateWindowEx(
        0,
        L"STATIC",
        L"500:",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        10, 170, 50, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    bill500TB = CreateWindowEx(
        0,
        L"STATIC",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
        70, 170, 150, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    HWND text200 = CreateWindowEx(
        0,
        L"STATIC",
        L"200:",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        10, 210, 50, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    bill200TB = CreateWindowEx(
        0,
        L"STATIC",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
        70, 210, 150, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    HWND text100 = CreateWindowEx(
        0,
        L"STATIC",
        L"100:",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        10, 250, 50, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    bill100TB = CreateWindowEx(
        0,
        L"STATIC",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
        70, 250, 150, 30,
        hwnd,
        NULL,
        hInstanceTB,
        NULL
    );

    clearTB = CreateWindowEx(
        0,
        L"BUTTON",
        L"Очистить",
        WS_CHILD | WS_VISIBLE,
        10, 330, 210, 30,
        hwnd,
        (HMENU)IDC_CLEAR_TB,
        hInstanceTB,
        NULL
    );

closeTB = CreateWindowEx(
        0,
        L"BUTTON",
        L"Назад",
        WS_CHILD | WS_VISIBLE,
        10, 370, 210, 30,
        hwnd,
        (HMENU)IDC_CLOSE_TB,
        hInstanceTB,
        NULL
    );

    hwndTB = hwnd;
    return hwndTB;
}

TakeBillsWindow::~TakeBillsWindow() {
    DestroyWindow(hwndTB);
}

LRESULT CALLBACK TakeBillsWindow::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_CLOSE_TB:
            PostMessage(hwnd, WM_CLOSE, 0, 0);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
