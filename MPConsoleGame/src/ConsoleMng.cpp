#include <ConsoleMng.h>
#include <SpriteLoader.h>

void ConsoleManager::getConsoleSize() {
	//Console screen buffer info is a struct (for rememberance sake)
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	m_cDimensions.columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	m_cDimensions.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	
}



void ConsoleManager::initializeConsoleBuffer()
{

	for (int rowsToGo = 0; rowsToGo < m_cDimensions.rows; ++rowsToGo)
	{
		vecChar addition;
		m_cBuffer.push_back(addition);

		for (int columnsToGo = 0; columnsToGo < m_cDimensions.columns; ++columnsToGo)
		{

			char addedChar = (char) ((int)'A' + rowsToGo);

			m_cBuffer.at(rowsToGo).push_back(addedChar);

		}

	}

}



void ConsoleManager::printConsoleBuffer()
{

	for (int rowsToGo = 0; rowsToGo < m_cBuffer.size(); ++rowsToGo )
	{

		for (int columnsToGo = 0; columnsToGo < m_cBuffer.at(0).size(); ++columnsToGo)
		{

			std::cout << m_cBuffer.at(rowsToGo).at(columnsToGo);

		}

		std::cout << std::endl;

	}

}

void ConsoleManager::placeGameObject(int posX, int posY, int objectID)
{



}

ConsoleManager::ConsoleManager()
{

	getConsoleSize();

	initializeConsoleBuffer();

}

ConsoleManager::~ConsoleManager()
{



}