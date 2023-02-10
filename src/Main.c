#include "B3KR.h"

int main(int* argc, char** argv)
{
    B3KR_Window* window = B3KR_CreateWindow(L"MNS", 0, 0, 500, 500, 0);
    B3KR_bool running = B3KR_TRUE;
    B3KR_Event event;

    while(running)
    {
        while(B3KR_PollEvent(&event, 0))
        {
            if(event.type == B3KR_QUIT)
            {
                running = B3KR_FALSE;
            }
        }
        
        printf("Hello, World!");
        B3KR_Delay(1);
    }

    return 0;
}