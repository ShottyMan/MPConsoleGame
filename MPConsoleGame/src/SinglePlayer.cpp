#include <SinglePlayer.h>
#include <conio.h>


void singlePlayerGame(ScreenManager* targetConsole)
{

	targetConsole->stringToConsole("Avoid red icons using arrow keys", 5, 35);
	targetConsole->stringToConsole("Starting game in: ", 6, 35);

	for (int seconds = 0; seconds < 5; ++seconds)
	{

		targetConsole->placePixel(6, 54, '5' - (seconds + 1));

		targetConsole->outputConsoleBuffer();

		Sleep(1000);

		clearScreen();

	}

	bool gameRun = true;

	while (gameRun)
	{

		if (GetKeyState(VK_ESCAPE) & 0x8000)
		{
			gameRun = false;
		}

		

		Sleep(REFRESH_TIME);

	}



}