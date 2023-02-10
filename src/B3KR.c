/*
    ██████╗ ██████╗ ██╗  ██╗██████╗ 
    ██╔══██╗╚════██╗██║ ██╔╝██╔══██╗
    ██████╔╝ █████╔╝█████╔╝ ██████╔╝
    ██╔══██╗ ╚═══██╗██╔═██╗ ██╔══██╗
    ██████╔╝██████╔╝██║  ██╗██║  ██║
    ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝

    This Library Was Made by ABN ALSRAG
    B3KR: بعكر: i dont know what does it mean
    
    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
        claim that you wrote the original software. If you use this software
        in a product, an acknowledgment in the product documentation would be
        appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
        misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
*/

#include "B3KR.h"
#include "B3KR_C.h"

B3KR_Event event;

#ifdef B3KR_System_Windows
LRESULT CALLBACK WindowProcedure(HWND hwnd, Uint32 msg, WPARAM wp, LPARAM lp)
{
    Uint64 timeStamp = GetMessageTime();

    switch(msg)
    {
        case WM_MOUSEMOVE:
        {
            event.type - B3KR_MOUSEMOTION;
            event.mouse.type = B3KR_MOUSEMOTION;
            event.mouse.position.x = GET_X_LPARAM(lp);
            event.mouse.position.y = GET_Y_LPARAM(lp);

            break;
        }
        case WM_LBUTTONDOWN:
        {
            event.type = B3KR_MOUSEBUTTONDOWN;
            event.mouse.type = B3KR_MOUSEBUTTONDOWN;
            event.mouse.button = B3KR_LeftButton;
            event.mouse.position.x = GET_X_LPARAM(lp);
            event.mouse.position.y = GET_Y_LPARAM(lp);

            break;
        }
        case WM_RBUTTONDOWN:
        {
            event.type = B3KR_MOUSEBUTTONDOWN;
            event.mouse.type = B3KR_MOUSEBUTTONDOWN;
            event.mouse.button = B3KR_RightButton;
            event.mouse.position.x = GET_X_LPARAM(lp);
            event.mouse.position.y = GET_Y_LPARAM(lp);

            break;
        }
        case WM_MBUTTONDOWN:
        {
            event.type = B3KR_MOUSEBUTTONDOWN;
            event.mouse.type = B3KR_MOUSEBUTTONDOWN;
            event.mouse.button = B3KR_MiddleButton;
            event.mouse.position.x = GET_X_LPARAM(lp);
            event.mouse.position.y = GET_Y_LPARAM(lp);

            break;
        }
        case WM_LBUTTONUP:
        {
            event.type = B3KR_MOUSEBUTTONUP;
            event.mouse.type = B3KR_MOUSEBUTTONUP;
            event.mouse.button = B3KR_LeftButton;
            event.mouse.position.x = GET_X_LPARAM(lp);
            event.mouse.position.y = GET_Y_LPARAM(lp);

            break;
        }
        case WM_RBUTTONUP:
        {
            event.type = B3KR_MOUSEBUTTONUP;
            event.mouse.type = B3KR_MOUSEBUTTONUP;
            event.mouse.button = B3KR_RightButton;
            event.mouse.position.x = GET_X_LPARAM(lp);
            event.mouse.position.y = GET_Y_LPARAM(lp);

            break;
        }
        case WM_MBUTTONUP:
        {
            event.type = B3KR_MOUSEBUTTONUP;
            event.mouse.type = B3KR_MOUSEBUTTONUP;
            event.mouse.button = B3KR_MiddleButton;
            event.mouse.position.x = GET_X_LPARAM(lp);
            event.mouse.position.y = GET_Y_LPARAM(lp);

            break;
        }
        case WM_MOUSEWHEEL:
        {
            event.type = B3KR_MOUSEWHEEL;
            event.mouse.type = B3KR_MOUSEWHEEL;
            event.mouse.scroll = GET_WHEEL_DELTA_WPARAM(wp);
            event.mouse.position.x = GET_X_LPARAM(lp);
            event.mouse.position.y = GET_Y_LPARAM(lp);
            break;
        }
        case WM_KEYDOWN:
        {
            event.type = B3KR_KEYDOWN;
            event.keyboard.type = B3KR_KEYDOWN;
            event.keyboard.key = wp;

            break;
        }
        case WM_KEYUP:
        {
            event.type = B3KR_KEYUP;
            event.keyboard.type = B3KR_KEYUP;
            event.keyboard.key = wp;

            break;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW+1));

            HPEN hPenOld;

            // Draw a red line
            HPEN hLinePen;
            COLORREF qLineColor;
            qLineColor = RGB(255, 0, 0);
            hLinePen = CreatePen(PS_SOLID, 7, qLineColor);
            hPenOld = (HPEN)SelectObject(hdc, hLinePen);

            MoveToEx(hdc, 100, 100, NULL);
            LineTo(hdc, 300, 100);
            LineTo(hdc, 300, 300);
            LineTo(hdc, 100, 300);
            LineTo(hdc, 100, 100);

            SelectObject(hdc, hPenOld);
            DeleteObject(hLinePen);

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_CREATE:
        {

            break;
        }
        case WM_MOVE:
        {

            break;
        }
        case WM_SIZE:
        {
            
            break;
        }
        case WM_CLOSE:
        {
            event.type = B3KR_QUIT;
            event.quit.type = B3KR_QUIT;

            break;
        }
        case WM_DESTROY:
        {

            break;   
        }
        default:
            DefWindowProcW(hwnd, msg, wp, lp);
            break;
    }
}
#endif

B3KR_bool B3KR_PollEvent(B3KR_Event* p_event, B3KR_Window* p_window)
{
#ifdef B3KR_System_Windows
    MSG msg = {0};

    int result = PeekMessage(&msg, (HWND)p_window, 0, 0, PM_REMOVE);
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    event.window = (B3KR_Window*)msg.hwnd;
    *p_event = event;

    if(msg.message != WM_MOUSEWHEEL)
        event.mouse.scroll = 0;

    if(msg.message != (WM_CLOSE&&WM_SIZE&&WM_MOVE&&WM_KEYUP&&WM_KEYDOWN&&WM_MOUSEWHEEL&&WM_MOUSEMOVE&&WM_LBUTTONDOWN&&WM_RBUTTONDOWN&&WM_MBUTTONDOWN&&WM_LBUTTONUP&&WM_RBUTTONUP&&WM_MBUTTONUP))
        event.type = 0;

    return result;
#endif
}

void B3KR_PostEvent(B3KR_Event* p_event)
{

}

B3KR_VirtualInput* CreateVirtualInput(char* p_text, Uint32 p_key, B3KR_bool p_click, Uint8 p_button, B3KR_bool p_move, Uint32 p_x, Uint32 p_y, Uint32 p_scrollX, Uint32 p_scrollY)
{
    B3KR_VirtualInput* input;

    input->keyboard.key = p_key;

    if(strlen(p_text) > 1)
    {
        input->keyboard.word = p_text;
    }

    if(p_click != B3KR_FALSE)
    {
        input->mouse.click = B3KR_TRUE;
        input->mouse.button = p_button;
    }

    if(p_move != B3KR_FALSE)
    {
        input->mouse.move = B3KR_TRUE;
        input->mouse.position.x = p_x;
        input->mouse.position.y = p_y;
    }

    input->mouse.scroll.x = p_scrollX;
    input->mouse.scroll.y = p_scrollY;

    return input;
}

void B3KR_SendVirtualInput(B3KR_VirtualInput* p_input)
{
#ifdef B3KR_System_Windows
    Uint16 button, up;
    INPUT input;
    ZeroMemory(&input, sizeof(input));

    switch(p_input->mouse.button)
    {
        case B3KR_LeftButton:
            button = MOUSEEVENTF_LEFTDOWN;
            up = MOUSEEVENTF_LEFTUP;
            break;
        case B3KR_RightButton:
            button = MOUSEEVENTF_RIGHTDOWN;
            up = MOUSEEVENTF_RIGHTUP;
            break;
        case B3KR_MiddleButton:
            button = MOUSEEVENTF_MIDDLEDOWN;
            up = MOUSEEVENTF_MIDDLEUP;
            break;
    }

    for(Uint32 i = 0; i < strlen(p_input->keyboard.word); i++)
    {
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = p_input->keyboard.word[i];
        input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
        SendInput(1, &input, sizeof(input));
    }

    input.type = INPUT_KEYBOARD;
    input.ki.wVk = p_input->keyboard.key;
    input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    
    SendInput(1, &input, sizeof(input));

    if(p_input->mouse.move == B3KR_TRUE)
    {
        mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, p_input->mouse.position.x, p_input->mouse.position.y, 0, 0);
    }
    
    if(p_input->mouse.click == B3KR_TRUE)
    {
        mouse_event(button, 0, 0, 0, 0);
        mouse_event(up, 0, 0, 0, 0);
    }

#endif
}

void B3KR_Init()
{
#ifdef B3KR_System_Windows
#endif
}

void B3KR_Terminate()
{
#ifdef B3KR_System_Windows
    PostQuitMessage(0);
#endif

    exit(0);
}

const char* B3KR_GetPlatform()
{
    #ifdef B3KR_System_Windows
        return "Windows";
    #elif B3KR_System_Linux
        return "Linux";
    #elif B3KR_System_Android
        return "Android";
    #elif B3KR_System_Iphone
        return "IOS";
    #elif B3KR_System_MacOS
        return "MacOS";
    #elif B3KR_System_FreeBSD
        return "FreeBSD";
    #else
        return "Unknown";
    #endif
}

void B3KR_Delay(Uint32 p_ms)
{
#ifdef B3KR_System_Windows
    Sleep(p_ms);
#endif
}

Uint32 B3KR_GetTicks()
{
#ifdef B3KR_System_Windows
#endif
}

Uint64 B3KR_GetTicks64()
{
#ifdef B3KR_System_Windows
#endif
}

Uint32 B3KR_GetSystemTicks()
{
#ifdef B3KR_System_Windows
    return GetTickCount();
#endif
}

Uint64 B3KR_GetSystemTicks64()
{
#ifdef B3KR_System_Windows
    
#endif
}

B3KR_Time B3KR_GetTime()
{
#ifdef B3KR_System_Windows
    SYSTEMTIME time;
    B3KR_Time bTime;
    GetLocalTime(&time);
    bTime.year = time.wYear;
    bTime.month = time.wMonth;
    bTime.dayOfWeek = time.wDayOfWeek;
    bTime.day = time.wDay;
    bTime.hour = time.wHour;
    bTime.minute = time.wMinute;
    bTime.second = time.wSecond;
    bTime.milliSecond = time.wMilliseconds;
    return bTime;
#endif
}

B3KR_Window* B3KR_CreateWindow(const Wchar* p_title, Uint32 p_x, Uint32 p_y, Uint32 p_w, Uint32 p_h, Uint32 p_flags)
{
#ifdef B3KR_System_Windows
    #define CLASS_NAME L"Window"
    WNDCLASSW window = {};
    window.hbrBackground = (HBRUSH)COLOR_WINDOW;
    window.hCursor = LoadCursor(NULL, IDC_ARROW);
    window.hInstance = GetModuleHandleW(0);
    window.lpszClassName = CLASS_NAME;
    window.lpfnWndProc = WindowProcedure;
    RegisterClassW(&window);
    HWND wnd = CreateWindowW(CLASS_NAME, p_title, WS_VISIBLE | WS_OVERLAPPEDWINDOW, p_x, p_y, p_w, p_h, NULL, NULL, NULL, NULL);
    return (B3KR_Window*)wnd;
#endif
}

B3KR_Window* B3KR_GrabMouse(B3KR_Window* p_window)
{
#ifdef B3KR_System_Windows
    return (B3KR_Window*)SetCapture((HWND)p_window);
#endif
}

void B3KR_DestroyWindow(B3KR_Window* p_window)
{
    if(p_window == NULL)
    {
        return;
    }

#ifdef B3KR_System_Windows
    DestroyWindow((HWND)p_window);
#endif
}

void B3KR_MaximizeWindow(B3KR_Window* p_window)
{
    if(p_window == NULL)
    {
        return;
    }

#ifdef B3KR_System_Windows
    ShowWindow((HWND)p_window, SW_MAXIMIZE);
#endif
}

void B3KR_MinimizeWindow(B3KR_Window* p_window)
{
    if(p_window == NULL)
    {
        return;
    }

#ifdef B3KR_System_Windows
    ShowWindow((HWND)p_window, SW_MINIMIZE);
#endif
}

void B3KR_ShowWindow(B3KR_Window* p_window)
{
    if(p_window == NULL)
    {
        return;
    }

#ifdef B3KR_System_Windows
    ShowWindow((HWND)p_window, SW_SHOW);
#endif
}

void B3KR_HideWindow(B3KR_Window* p_window)
{
    if(p_window == NULL)
    {
        return;
    }

#ifdef B3KR_System_Windows
    ShowWindow((HWND)p_window, SW_HIDE);
#endif
}

void B3KR_ResetWindow(B3KR_Window* p_window)
{
    if(p_window == NULL)
    {
        return;
    }

#ifdef B3KR_System_Windows
    ShowWindow((HWND)p_window, SW_RESTORE);
#endif
}

B3KR_Renderer* B3KR_CreateRenderer()
{
#ifdef B3KR_System_Windows
#endif
}

int B3KR_SimpleMessageBox(B3KR_Window* p_window, const Wchar* p_message, const Wchar* p_title, Uint32 p_flags)
{
#ifdef B3KR_System_Windows
    MessageBoxW((HWND)p_window, p_message, p_title, p_flags);
#endif
}

B3KR_NotificationData* B3KR_CreateNotificationData(B3KR_Window* p_window, const char* p_infoTitle, const char* p_infoText, const char* p_toolTip, B3KR_Surface* p_icon)
{
    B3KR_NotificationData* data;
#ifdef B3KR_System_Windows
    memcpy(data->infoTitle, p_infoTitle, 64);
    memcpy(data->infoText, p_infoText, 256);
    memcpy(data->toolTip, p_toolTip, 128);
    data->icon = p_icon;
    data->window = p_window;
#endif

    return data;
}

void B3KR_AddNotification(B3KR_NotificationData* p_data)
{
#ifdef B3KR_System_Windows
    NOTIFYICONDATA nid = {0};
    nid.cbSize = sizeof(nid);
    nid.hWnd = (HWND)p_data->window;
    nid.uFlags = NIF_INFO;
    p_data->id = nid.uID;
    memcpy(nid.szTip, p_data->toolTip, 128);
    memcpy(nid.szInfoTitle, p_data->infoTitle, 64);
    memcpy(nid.szInfo, p_data->infoText, 256);
    Shell_NotifyIcon(NIM_ADD, &nid);
#endif
}

void B3KR_DestroyNotification(B3KR_NotificationData* p_data)
{
#ifdef B3KR_System_Windows
    NOTIFYICONDATA nid = {0};
    nid.uID = p_data->id;
    nid.hWnd = (HWND)p_data->window;
    Shell_NotifyIcon(NIM_DELETE, &nid);
#endif
}

void B3KR_DeleteRecycleBin(const char* p_path)
{
#ifdef B3KR_System_Windows
    SHEmptyRecycleBin(NULL, p_path, 0);
#endif
}