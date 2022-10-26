#include <ConsoleMng.h>

consoleDimensions GetConsoleSize() {
	//Console screen buffer info is a struct (for rememberance sake)
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	consoleDimensions returnVar;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	returnVar.columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	returnVar.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return returnVar;
}

void initializeConsoleBuffer(consoleDimensions inConsoleSize, std::vector<std::vector<char>>)
{

	for (int rowsToGo = 0; rowsToGo < inConsoleSize.rows; ++rowsToGo)
	{

		for (int columnsToGo = 0; columnsToGo < inConsoleSize.columns; ++columnsToGo)
		{



		}

	}

}