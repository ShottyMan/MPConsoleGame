#pragma once
#include <Windows.h>
#include <vector>

struct consoleDimensions {

	int columns;
	int rows;
};

consoleDimensions GetConsoleSize();

void initializeConsoleBuffer(consoleDimensions, std::vector<std::vector<char>>);