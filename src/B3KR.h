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

#ifndef B3KR_H
#define B3KR_H

// O------------------------------------------------------------------------------O
// | INCLUDES                                                                     |
// O------------------------------------------------------------------------------O
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#ifdef __CC_ARM
/* ARM's compiler throws warnings if we use an enum*/
/**
 * \brief False boolean value. Equals 0
*/
#define B3KR_FALSE 0
/** \brief True boolean value. Equals 1*/
#define B3KR_TRUE 1
/** \brief Boolean type. Ranges between 0, 1;*/
typedef unsigned int B3KR_bool;
#else
/**
 * \brief Boolean type. Ranges between 0, 1;
*/
typedef enum B3KR_bool
{
    B3KR_FALSE = 0, /** \brief False boolean value. Equals 0*/
    B3KR_TRUE = 1 /** \brief True boolean value. Equals 1*/
} B3KR_bool;
#endif

/**
 * \brief A signed 8-bit integer type. Ranges between 127, -128
 */
typedef signed char Sint8;
#define B3KR_MAX_SINT8   ((Sint8)0x7F)           /* 127 */
#define B3KR_MIN_SINT8   ((Sint8)(~0x7F))        /* -128 */
/**
 * \brief An unsigned 8-bit integer type. Ranges between 255, 0
 */
typedef unsigned char Uint8;
#define B3KR_MAX_UINT8   ((Uint8)0xFF)           /* 255 */
#define B3KR_MIN_UINT8   ((Uint8)0x00)           /* 0 */
/**
 * \brief A signed 16-bit integer type. Ranges between 32767, -32768
 */
typedef short Sint16;
#define B3KR_MAX_SINT16  ((Sint16)0x7FFF)        /* 32767 */
#define B3KR_MIN_SINT16  ((Sint16)(~0x7FFF))     /* -32768 */
/**
 * \brief An unsigned 16-bit integer type. Ranges between 65535, 0
 */
typedef unsigned short Uint16;
#define B3KR_MAX_UINT16  ((Uint16)0xFFFF)        /* 65535 */
#define B3KR_MIN_UINT16  ((Uint16)0x0000)        /* 0 */
/**
 * \brief A signed 32-bit integer type. Ranges between 2147483647, -2147483648
 */
typedef int Sint32;
#define B3KR_MAX_SINT32  ((Sint32)0x7FFFFFFF)    /* 2147483647 */
#define B3KR_MIN_SINT32  ((Sint32)(~0x7FFFFFFF)) /* -2147483648 */
/**
 * \brief An unsigned 32-bit integer type. Ranges between 4294967295, 0
 */
typedef unsigned int Uint32;
#define B3KR_MAX_UINT32  ((Uint32)0xFFFFFFFFu)   /* 4294967295 */
#define B3KR_MIN_UINT32  ((Uint32)0x00000000)    /* 0 */

/**
 * \brief A signed 64-bit integer type. Ranges between 9223372036854775807, -9223372036854775808
 */
typedef long long Sint64;
#define B3KR_MAX_SINT64  ((Sint64)0x7FFFFFFFFFFFFFFFll)      /* 9223372036854775807 */
#define B3KR_MIN_SINT64  ((Sint64)(~0x7FFFFFFFFFFFFFFFll))   /* -9223372036854775808 */
/**
 * \brief An unsigned 64-bit integer type. Ranges between 18446744073709551615, 0
 */
typedef unsigned long long Uint64;
#define B3KR_MAX_UINT64  ((Uint64)0xFFFFFFFFFFFFFFFFull)     /* 18446744073709551615 */
#define B3KR_MIN_UINT64  ((Uint64)(0x0000000000000000ull))   /* 0 */

typedef unsigned short Wchar; /** \brief An unsigned 16-bit wide character type*/

/**
 * Signed integer vector2 type
*/
typedef struct B3KR_Point
{
    Sint32 x, y;
} B3KR_Vector2;

/**
 * Signed floating vector2 type
*/
typedef struct B3KR_Pointf
{
    float x, y;
} B3KR_Vector2f;

/**
 * 
*/
typedef struct B3KR_Rect
{
    Sint32 x, y, w, h;
} B3KR_Rect;

/**
 * 
*/
typedef struct B3KR_Rectf
{
    float x, y, w, h;
} B3KR_Rectf;

typedef struct B3KR_Color
{
    Uint8 r, b, g, a;
} B3KR_Color;

/**
 * \brief Values of common colors
*/
static const B3KR_Color
B3KR_GREY =    {192, 192, 192, 255}, B3KR_DARK_GREY=     {128, 128, 128, 255}, B3KR_VERY_DARK_GREY =    {64, 64, 64, 255},
B3KR_RED =     {255, 0, 0, 255},     B3KR_DARK_RED =     {128, 0, 0, 255},     B3KR_VERY_DARK_RED =     {64, 0, 0, 255},
B3KR_YELLOW =  {255, 255, 0, 255},   B3KR_DARK_YELLOW =  {128, 128, 0, 255},   B3KR_VERY_DARK_YELLOW =  {64, 64, 0, 255},
B3KR_GREEN =   {0, 255, 0, 255},     B3KR_DARK_GREEN =   {0, 128, 0, 255},     B3KR_VERY_DARK_GREEN =   {0, 64, 0, 255},
B3KR_CYAN =    {0, 255, 255, 255},   B3KR_DARK_CYAN =    {0, 128, 128, 255},   B3KR_VERY_DARK_CYAN =    {0, 64, 64, 255},
B3KR_BLUE =    {0, 0, 255, 255},     B3KR_DARK_BLUE =    {0, 0, 128, 255},     B3KR_VERY_DARK_BLUE =    {0, 0, 64, 255},
B3KR_MAGENTA = {255, 0, 255, 255},   B3KR_DARK_MAGENTA = {128, 0, 128, 255},   B3KR_VERY_DARK_MAGENTA = {64, 0, 64, 255},
B3KR_WHITE =   {255, 255, 255, 255}, B3KR_BLACK =        {0, 0, 0, 255},       B3KR_BLANK =             {0, 0, 0, 0};

/**
 * 
*/
typedef enum B3KR_WindowFlags
{
    B3KR_WindowShown = 0,
} B3KR_WindowFlags;

/**
 * \brief A window object
*/
typedef struct B3KR_Window B3KR_Window;

/**
 * 
*/
typedef struct B3KR_Surface
{
    Uint32 flags;
    Uint32 width, height;
    void* pixels;   
} B3KR_Surface;

/**
 * A renderer object
*/
typedef struct B3KR_Renderer B3KR_Renderer;

/**
 * All event handling messages
*/
typedef enum B3KR_EventType
{
    /* Application */
    B3KR_NoEvent, /** */
    B3KR_QUIT, /** Quit event (by user)*/
    B3KR_APPTERMINATING, /** The application is being terminated by the OS*/
    /**
     * Called on iOS in applicationDidReceiveMemoryWarning()
     * Called on Android in onLowMemory()
    */
    B3KR_APP_LOWMEMORY, /** The application is low on memory, free memory if possible. */
    B3KR_WINDOWRESIZE, /** The window has been resized*/
    B3KR_GAINFOCUS, /** The window has gained focus*/
    B3KR_LOSTFOCUS, /** The window has lost focus*/
    B3KR_PAINT, /** The window should repaint it self*/

    /* Keyboard */
    B3KR_KEYUP, /** Key released*/
    B3KR_KEYDOWN, /** Key pressed*/
    B3KR_TEXTEDITING, /** Keyboard text editing (composition) */
    B3KR_TEXTINPUT, /** Keyboard text input */
    B3KR_KEYMAPCHANGED, /** Keymap changed due to a system event such as an input language or keyboard layout change*/
    B3KR_TEXTEDITING_EXT, /** Extended keyboard text editing (composition) */

    /* Mouse */
    B3KR_MOUSEMOTION, /** Mouse moved */
    B3KR_MOUSEBUTTONDOWN, /** Mouse button pressed */
    B3KR_MOUSEBUTTONUP, /** Mouse button released */
    B3KR_MOUSEWHEEL, 

    /* Joystick */
    /* Game Controller */
    /* Touch */
    /* Gesture */

    /* Drag and drop */
    B3KR_DROPFILE, /** The system requests a file open */
    B3KR_DROPTEXT, /** text drag and drop event */
    B3KR_DROPBEGIN, /** A new set of drops is beginning (NULL filename) */
    B3KR_DROPCOMPLETE, /** Current set of drops is now complete (NULL filename) */

    /* Sensor */
    B3KR_SENSORUPDATE, /** A sensor was updated */

    /* Audio */
    B3KR_AUDIODEVICEADDED, /** A new audio device is available */
    B3KR_AUDIODEVICEREMOVED, /** An audio device has been removed. */

    /* Clipboard */
    B3KR_CLIPBOARDUPDATE, /** The clipboard or primary selection changed */
} B3KR_EventType;

/**
 * 
*/
typedef enum B3KR_MouseButton
{
    B3KR_LeftButton,
    B3KR_RightButton,
    B3KR_MiddleButton,
    B3KR_ForwardButton,
    B3KR_BackButton
} B3KR_MouseButton;

/**
 * 
*/
typedef enum B3KR_KeyCodes
{
    B3KRK_Space               = 32,
    B3KRK_Apostrophe          = 39, /* ' */
    B3KRK_Comma               = 44, /* , */
    B3KRK_Minus               = 45, /* - */
    B3KRK_Period              = 46, /* . */
    B3KRK_Slash               = 47, /* / */

    B3KRK_D0                  = 48, /* 0 */
    B3KRK_D1                  = 49, /* 1 */
    B3KRK_D2                  = 50, /* 2 */
    B3KRK_D3                  = 51, /* 3 */
    B3KRK_D4                  = 52, /* 4 */
    B3KRK_D5                  = 53, /* 5 */
    B3KRK_D6                  = 54, /* 6 */
    B3KRK_D7                  = 55, /* 7 */
    B3KRK_D8                  = 56, /* 8 */
    B3KRK_D9                  = 57, /* 9 */

    B3KRK_Semicolon           = 59, /* ; */
    B3KRK_Equal               = 61, /* = */

    B3KRK_A                   = 65,
    B3KRK_B                   = 66,
    B3KRK_C                   = 67,
    B3KRK_D                   = 68,
    B3KRK_E                   = 69,
    B3KRK_F                   = 70,
    B3KRK_G                   = 71,
    B3KRK_H                   = 72,
    B3KRK_I                   = 73,
    B3KRK_J                   = 74,
    B3KRK_K                   = 75,
    B3KRK_L                   = 76,
    B3KRK_M                   = 77,
    B3KRK_N                   = 78,
    B3KRK_O                   = 79,
    B3KRK_P                   = 80,
    B3KRK_Q                   = 81,
    B3KRK_R                   = 82,
    B3KRK_S                   = 83,
    B3KRK_T                   = 84,
    B3KRK_U                   = 85,
    B3KRK_V                   = 86,
    B3KRK_W                   = 87,
    B3KRK_X                   = 88,
    B3KRK_Y                   = 89,
    B3KRK_Z                   = 90,

    B3KRK_LeftBracket         = 91,  /* [ */
    B3KRK_Backslash           = 92,  /* \ */
    B3KRK_RightBracket        = 93,  /* ] */
    B3KRK_GraveAccent         = 96,  /* ` */

    B3KRK_World1              = 161, /* non-US #1 */
    B3KRK_World2              = 162, /* non-US #2 */

    /* Function keys */
    B3KRK_Escape              = 256,
    B3KRK_Enter               = 257,
    B3KRK_Tab                 = 258,
    B3KRK_Backspace           = 259,
    B3KRK_Insert              = 260,
    B3KRK_Delete              = 261,
    B3KRK_Right               = 262,
    B3KRK_Left                = 263,
    B3KRK_Down                = 264,
    B3KRK_Up                  = 265,
    B3KRK_PageUp              = 266,
    B3KRK_PageDown            = 267,
    B3KRK_Home                = 268,
    B3KRK_End                 = 269,
    B3KRK_CapsLock            = 280,
    B3KRK_ScrollLock          = 281,
    B3KRK_NumLock             = 282,
    B3KRK_PrintScreen         = 283,
    B3KRK_Pause               = 284,
    B3KRK_F1                  = 290,
    B3KRK_F2                  = 291,
    B3KRK_F3                  = 292,
    B3KRK_F4                  = 293,
    B3KRK_F5                  = 294,
    B3KRK_F6                  = 295,
    B3KRK_F7                  = 296,
    B3KRK_F8                  = 297,
    B3KRK_F9                  = 298,
    B3KRK_F10                 = 299,
    B3KRK_F11                 = 300,
    B3KRK_F12                 = 301,
    B3KRK_F13                 = 302,
    B3KRK_F14                 = 303,
    B3KRK_F15                 = 304,
    B3KRK_F16                 = 305,
    B3KRK_F17                 = 306,
    B3KRK_F18                 = 307,
    B3KRK_F19                 = 308,
    B3KRK_F20                 = 309,
    B3KRK_F21                 = 310,
    B3KRK_F22                 = 311,
    B3KRK_F23                 = 312,
    B3KRK_F24                 = 313,
    B3KRK_F25                 = 314,

    /* Keypad */
    B3KRK_KP0                 = 320,
    B3KRK_KP1                 = 321,
    B3KRK_KP2                 = 322,
    B3KRK_KP3                 = 323,
    B3KRK_KP4                 = 324,
    B3KRK_KP5                 = 325,
    B3KRK_KP6                 = 326,
    B3KRK_KP7                 = 327,
    B3KRK_KP8                 = 328,
    B3KRK_KP9                 = 329,
    B3KRK_KPDecimal           = 330,
    B3KRK_KPDivide            = 331,
    B3KRK_KPMultiply          = 332,
    B3KRK_KPSubtract          = 333,
    B3KRK_KPAdd               = 334,
    B3KRK_KPEnter             = 335,
    B3KRK_KPEqual             = 336,

    B3KRK_LeftShift           = 340,
    B3KRK_LeftControl         = 341,
    B3KRK_LeftAlt             = 342,
    B3KRK_LeftSuper           = 343,
    B3KRK_RightShift          = 344,
    B3KRK_RightControl        = 345,
    B3KRK_RightAlt            = 346,
    B3KRK_RightSuper          = 347,
    B3KRK_Menu                = 348
} B3KR_KeyCodes;

/**
 * Event message type for mouse events
*/
typedef struct B3KR_MouseEvent
{
    Uint32 type;                /** ::B3KR_MOUSEBUTTONDOWN or ::B3KR_MOUSEBUTTONUP or ::B3KR_MOUSEWHEEL or ::B3KR_MOUSEMOTION */
    Uint32 timestamp;           /** In milliseconds, populated using B3KR_GetTicks() */
    Uint32 which;               /** The mouse instance id, or B3KR_TOUCH_MOUSEID */
    Uint8 button;               /** The mouse button index */
    Uint8 clicks;               /** 1 for single-click, 2 for double-click, etc. */
    Uint8 padding1;
    B3KR_Vector2 position;      /** Position relative to the window*/
    B3KR_Vector2 realPosition;  /** Position relative to the disktop*/
    Sint16 scroll;              /** The amount scrolled, x for horizontall scrolling postive for right and negative for left, y for verticall scrolling positive away from the user and negative toward the user */
} B3KR_MouseEvent;

/**
 * Event message type for keyboard events
*/
typedef struct B3KR_KeyboardEvent
{
    Uint32 type;        /** ::B3KR_KEYDOWN or ::B3KR_KEYUP */
    Uint32 timestamp;   /** In milliseconds, populated using B3KR_GetTicks() */
    Uint8 repeat;       /** Non-zero if this is a key repeat */
    Uint32 key;         /** */
} B3KR_KeyboardEvent;

/**
 * 
*/
typedef struct B3KR_QuitEvent
{
    Uint32 type;
    Uint32 timeStamp;
} B3KR_QuitEvent;

/**
 * Message type for handling events
*/
typedef struct B3KR_Event
{
    B3KR_QuitEvent quit;
    B3KR_MouseEvent mouse;
    B3KR_KeyboardEvent keyboard;
    Uint32 type;
    B3KR_Window* window;
} B3KR_Event;

/**
 * \brief Cursor object
*/
typedef struct B3KR_Cursor B3KR_Cursor;

/**
 * 
*/
typedef struct B3KR_NotificationData B3KR_NotificationData;

/**
 * 
*/
typedef struct B3KR_VirtualMouse
{
    B3KR_bool move, click;
    B3KR_Vector2 position;
    B3KR_Vector2 scroll;
    Uint32 button;
} B3KR_VirtualMouse;

/**
 * 
*/
typedef struct B3KR_VirtualKeyboard
{
    Uint32 key;
    char* word;
} B3KR_VirtualKeyboard;

/**
 * 
*/
typedef struct B3KR_VirtualGamepad
{

} B3KR_VirtualGamepad;

/**
 * 
*/
typedef struct B3KR_VirtualInput
{
    B3KR_VirtualMouse mouse;
    B3KR_VirtualKeyboard keyboard;
    B3KR_VirtualGamepad gamepad;
} B3KR_VirtualInput;

/**
 * 
*/
typedef struct B3KR_Time
{
    Uint16 year, month, dayOfWeek, day, hour, minute, second, milliSecond;
} B3KR_Time;

/**
 * 
*/
B3KR_bool B3KR_PollEvent(B3KR_Event* p_event, B3KR_Window* p_window);

/**
 * 
*/
B3KR_VirtualInput* CreateVirtualInput(char* p_text, Uint32 p_key, B3KR_bool p_click, Uint8 p_button, B3KR_bool p_move, Uint32 p_x, Uint32 p_y, Uint32 p_scrollX, Uint32 p_scrollY);

/**
 * 
*/
void B3KR_SendVirtualInput(B3KR_VirtualInput* p_input);

/**
 * Initialize B3KR
*/
void B3KR_Init();

/**
 * Closes the program
*/
void B3KR_Terminate();

/**
 * Get the name of the platform.
 *
 * Here are the names returned for supported platforms:
 *
 * - "Windows"
 * - "MacOS"
 * - "Linux"
 * - "IOS"
 * - "Android"
 * - "FreeBSD"
 *
 * \returns the name of the platform. If the correct platform name is not
 *          available, returns a string beginning with the text "Unknown".
 *
 * \since This function is available since B3KR 0.0.1.
 */
const char* B3KR_GetPlatform();

/**
 * Sleeps the program for amount of time in milliseconds
*/
void B3KR_Delay(Uint32 p_ms);

/**
 * Get the number of milliseconds since the program started. 32-Bit
*/
Uint32 B3KR_GetTicks();

/**
 * Get the number of milliseconds since the program started. 64-Bit
*/
Uint64 B3KR_GetTicks64();

/**
 * Get the number of milliseconds since the system started. 32-Bit
*/
Uint32 B3KR_GetSystemTicks();

/**
 * Get the number of milliseconds since the system started. 64-Bit
*/
Uint64 B3KR_GetSystemTicks64();

/**
 * 
*/
B3KR_Time B3KR_GetTime();

/**
 * Creats an B3KR_Window
 * \return A pointer to an B3KR_Window
*/
B3KR_Window* B3KR_CreateWindow(const Wchar* p_title, Uint32 p_x, Uint32 p_y, Uint32 p_w, Uint32 p_h, Uint32 p_flags);

/**
 * 
*/
B3KR_Window* B3KR_GrabMouse(B3KR_Window* p_window);

/**
 * Destroys the B3KR_Window
*/
void B3KR_DestroyWindow(B3KR_Window* p_window);

/**
 * Maximize the B3KR_Window
*/
void B3KR_MaximizeWindow(B3KR_Window* p_window);

/**
 * Minimize the B3KR_Window
*/
void B3KR_MinimizeWindow(B3KR_Window* p_window);

/**
 * Shows the B3KR_Window
*/
void B3KR_ShowWindow(B3KR_Window* p_window);

/**
 * Hides the B3KR_Window
*/
void B3KR_HideWindow(B3KR_Window* p_window);

/**
 * Raise the B3KR_Window
*/
void B3KR_RaiseWindow(B3KR_Window* p_window);

/**
 * Resets the B3KR_Window to it's default state
*/
void B3KR_ResetWindow(B3KR_Window* p_window);

/**
 * Creats an B3KR_Renderer
 * \return A pointer to an B3KR_Renderer
*/
B3KR_Renderer* B3KR_CreateRenderer();

/**
 * Creats a simple message box
*/
int B3KR_SimpleMessageBox(B3KR_Window* p_window, const Wchar* p_message, const Wchar* p_title, Uint32 p_flags);

/**
 * Creats notification data typedef structre for you
*/
B3KR_NotificationData* B3KR_CreateNotificationData(B3KR_Window* p_window, const char p_infoTitle[], const char p_infoText[], const char p_toolTip[], B3KR_Surface* p_icon);

/**
 * Add notification item
*/
void B3KR_AddNotification(B3KR_NotificationData* p_data);

/**
 * Delete notification item
*/
void B3KR_DestroyNotification(B3KR_NotificationData* p_data);

/**
 * 
*/
void B3KR_DeleteRecycleBin(const char* p_path);

#endif