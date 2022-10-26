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
    consoleDimensions sizeOfConsole = GetConsoleSize();

    printf("columns: %d\n", sizeOfConsole.columns);
    printf("rows: %d\n", sizeOfConsole.rows);

    std::vector<std::vector<char>> consoleCoord;

    

    
}
