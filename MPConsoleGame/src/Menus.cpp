#include <Menus.h>


void mainMenu(LogSystem* LogClass)
{


	ScreenManager mainScreen;

	bool exit = false;

	unsigned short currentOption = 0;

	mainScreen.writeBufferRow("start", 14, 10);

	mainScreen.writeBufferRow("quit", 16, 10);

	mainScreen.stringToConsole("String To console test!\nI feel Great", 13, 50);

	//Use this for checking inputs
	while (!exit) {

		mainScreen.outputConsoleBuffer();

		

		if (GetKeyState(VK_UP) & 0x8000)
		{

			mainScreen.placePixel(14, 9, '-');
			mainScreen.placePixel(16, 9, ' ');
			currentOption = 1;

		}
		else if (GetKeyState(VK_DOWN) & 0x8000)
		{

			mainScreen.placePixel(14, 9, ' ');
			mainScreen.placePixel(16, 9, '-');
			currentOption = 2;
		}
		else if (GetKeyState(VK_RETURN) & 0x8000)
		{

			switch (currentOption)
			{

			case 1:

				selectGameMode(&mainScreen, LogClass);

				break;
			case 2:

				exit = true;

				break;

			}

		}
		Sleep(REFRESH_TIME);

		clearScreen();
		//system("clear");
		//std::cout << "\033[2J\033[1;1H";
		//std::cout << std::flush;
		//clearConsole();


	}

}