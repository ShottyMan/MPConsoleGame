#include <ScreenManager.h>

void clearScreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}


struct ConsoleDimensions_s ScreenManager::getConsoleSize() {
	//Console screen buffer info is a struct (for rememberance sake)
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	m_cDimensions.columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	m_cDimensions.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return m_cDimensions;
}

void ScreenManager::clearBuffer()
{


	for (int rowIndex = 0; rowIndex < m_cDimensions.rows; ++rowIndex)
	{

		for (int columnIndex = 0; columnIndex < m_cDimensions.columns; ++columnIndex)
		{

			m_cBuffer.at(rowIndex).at(columnIndex) = ' ';

		}



	}

}

ScreenManager::ScreenManager()
{
	std::cout << "\x1B[?25l";

	m_cDimensions.columns = 0;

	m_cDimensions.rows = 0;

	getConsoleSize();

	std::string temp;

	for (int rowIndex = 0; rowIndex < m_cDimensions.rows; ++rowIndex)
	{
		m_cBuffer.push_back(temp);

		for (int columnIndex = 0; columnIndex < m_cDimensions.columns; ++columnIndex)
		{

			m_cBuffer.at(rowIndex).push_back(' ');

		}

	}


}

ScreenManager::~ScreenManager()
{

	std::cout << "\033[2J\033[1;1H";

}

void ScreenManager::outputConsoleBuffer()
{

	for (int rowIndex = 0; rowIndex < m_cDimensions.rows; ++rowIndex)
	{
		if (rowIndex < (m_cDimensions.rows - 1))
			std::cout << m_cBuffer.at(rowIndex) << std::endl;
		else
			std::cout << m_cBuffer.at(rowIndex);

	}

}

void ScreenManager::writeBufferRow(std::string input, int row, int start)
{
	if (m_cDimensions.rows < (input.size() + start))
		throw std::invalid_argument("Overrun console buffer. Please try again.");
	else
	{
		int stringIndex = 0;
		for (int index = start; index < (input.size() + start); ++index)
		{

			m_cBuffer.at(row).at(index) = input.at(stringIndex);
			stringIndex++;
		}

	}

}

void ScreenManager::placePixel(int row, int column, char input)
{

	m_cBuffer.at(row).at(column) = input;

}

void ScreenManager::swapPixel(int inirow, int inicolumn, int frow, int fcolumn)
{

	char temp;

	temp = m_cBuffer.at(inirow).at(inicolumn);

	m_cBuffer.at(inirow).at(inicolumn) = m_cBuffer.at(frow).at(fcolumn);

	m_cBuffer.at(frow).at(fcolumn) = temp;

}

void ScreenManager::writeBufferRowLine(char input, int row)
{

	for (int index = 0; index < m_cDimensions.columns; ++index)
	{

		m_cBuffer.at(row).at(index) = input;

	}

}

void ScreenManager::stringToConsole(std::string input, int row, int column)
{
	int s_Column = column;
	for (int index = 0; index < input.size(); ++index)
	{

		if (input.at(index) == '\n')
		{

			s_Column = column-1;
			++row;
		}
		else
		{

			m_cBuffer.at(row).at(s_Column) = input.at(index);

		}

		++s_Column;
	}


}

void ScreenManager::stringDelToConsole(std::string input, int row, int column, char replacement=' ')
{
	int s_Column = column;
	for (int index = 0; index < input.size(); ++index)
	{

		if (input.at(index) == '\n')
		{

			s_Column = column - 1;
			++row;
		}
		else
		{

			m_cBuffer.at(row).at(s_Column) = replacement;

		}

		++s_Column;
	}


}