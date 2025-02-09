﻿
#include "pch.h"
#include "BaseWindow.h"
#include <ctime>
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(325);
    srand(unsigned int(time(NULL)));
    BaseWindow game({ WINDOW_WIDTH, WINDOW_HEIGHT });
    game.Run(hInstance, lpCmdLine, nCmdShow);
}