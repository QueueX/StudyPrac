#include <Windows.h>

class TakeBillsWindow
{
public:
    TakeBillsWindow(HINSTANCE hInstance);
    HWND Create();
    ~TakeBillsWindow();

    void BackToMenu();

private:
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    static HINSTANCE hInstanceTB;
    HWND hwndTB;
    HWND inputTB;
    HWND enterTB;
    HWND closeTB;
    HWND clearTB;
    HWND bill5000TB;
    HWND bill2000TB;
    HWND bill1000TB;
    HWND bill500TB;
    HWND bill200TB;
    HWND bill100TB;
};