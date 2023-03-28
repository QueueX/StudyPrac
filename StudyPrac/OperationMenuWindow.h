#include <Windows.h>

class OperationMenuWindow
{
public:
    OperationMenuWindow();
    OperationMenuWindow(HINSTANCE hInstance);
    HWND Create();
    ~OperationMenuWindow();

private:
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    HINSTANCE hInstanceOM;
    HWND hwndOM;
    HWND TakeBillsOM;
    HWND PutBillsOM;
    HWND ExitOM;
    HWND GetBalanceOM;
    HWND ProfileOM;
};

