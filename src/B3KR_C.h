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

#ifndef B3KR_C_H
#define B3KR_C_H

#include "B3KR.h"
#if defined(_WIN32) || defined(__WINRT__)
    #define B3KR_System_Windows
    #if _WIN64
        #define B3KR_System_Windows_64
    #else 
        #define B3KR_System_Windows_32
    #endif
#elif defined(ANDROID) || defined(__ANDROID__)
    #define B3KR_System_Android
#elif defined(__APPLE__) || defined(__MACH__)
    #include <AvailabilityMacros.h>
    #include "TargetConditionals.h"
    #define B3KR_System_AppleOS
    #if TARGET_OS_IPHONE
        #if TARGET_IPHONE_SIMULATOR
            #define B3KR_System_IOS_Simulator
        #endif
        #define B3KR_System_Iphone
    #elif TARGET_OS_MAC
        #define B3KR_System_MacOS
        // if MAC_OS_X_VERSION_MIN_REQUIRED < 1070
        //  #error B3KR for Mac OS X only supports deploying on 10.7 and above.
    #else
        #define B3KR_System_Unidentified_Apple_OS
    #endif
#elif defined(__linux__) || defined(__linux) || defined(linux)
    #define B3KR_System_Linux
#elif defined(__unix__) || defined(__unix) 
    #define B3KR_System_Unix
#elif defined(__FreeBSD__)
    #define B3KR_System_FreeBSD
#elif defined(BSD)
    #define B3KR_System_BSD
#elif defined(__OpenBSD__)
    #define B3KR_System_OpenBSD
#elif defined(__EMSCRIPTEN__)
   #define B3KR_System_Emscripten
else
    #define B3KR_System_Unidentified
#endif

#ifdef B3KR_System_Windows
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <process.h>
#endif

#define B3KR_BIT(x) (1 << x)

typedef struct B3KR_NotificationData
{
    B3KR_Surface* icon;
    B3KR_Window* window;
    Uint32 flags;
    Wchar toolTip[128];
    Wchar infoText[256];
    Wchar infoTitle[64];
    Uint32 id;
} B3KR_NotificationData;

void B3KR_PostEvent(B3KR_Event* p_event);

#endif