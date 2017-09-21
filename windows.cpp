/* Library to windows */
#include <windows.h>

/* Declaration of the function */
LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);

/* The main function */
int WINAPI WinMain(
                   HINSTANCE hinstance, /* First argument : instance handle */
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, /* Pointer Comand line */
                   int nCmdShow
                   )
{
    HWND hwnd; // Handler
    MSG msg; // Location message
    WNDCLASS wc; // Property Window

    wc.style = 0;
    wc.lpfnWndProc = MainWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hinstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
    wc.lpszMenuName =  NULL;
    wc.lpszClassName = "MyWinClass";

    // Test register class
    if(!RegisterClass(&wc)) return FALSE;


    /* Create Window */
    hwnd = CreateWindow(
                        "MyWinClass",
                        "Title", // Title
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        400, // Size
                        300, // Size
                        NULL,
                        NULL,
                        hinstance,
                        NULL
                        );

    // Test hwnd
    if (!hwnd) return FALSE;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0) > 0 )
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:

            return 0;

        /* Destruct window */
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}
