// MPConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <WinSock2.h>
#include <winioctl.h>
#include <Windows.h>
#include <ConsoleMng.h>
#include <vector>


int main()
{
    ConsoleManager screen;
    

    screen.printConsoleBuffer();
    
    return 0;
    
}
