#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <iostream>

struct ConsoleDimensions_s
{
	int rows;
	int columns;

};

void clearScreen();

class ScreenManager
{

private:
	std::vector<std::string> m_cBuffer;
	ConsoleDimensions_s m_cDimensions;

public:


	ScreenManager();
	~ScreenManager();

	void outputConsoleBuffer();
	struct ConsoleDimensions_s getConsoleSize();

	//Writes to a certai row
	void writeBufferRow(std::string input, int row, int start = 0);
	//Overrides row
	void writeBufferRowLine(char input, int row);

	void swapPixel(int inirow, int inicolumn, int frow, int fcolumn);

	void placePixel(int row, int column, char input);

	void stringToConsole(std::string input, int row, int column);

	void clearBuffer();

};