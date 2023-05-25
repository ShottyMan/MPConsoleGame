#include <SinglePlayer.h>
#include <conio.h>
#include <PlayerPawn.h>


void singlePlayerGame(ScreenManager* targetConsole, LogSystem* LogClass)
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

	PlayerPawn FirstPlayer(targetConsole, "/\\", 0, 0, 5, 1, REFRESH_TIME, LogClass);

	while (gameRun)
	{

		if (GetKeyState(VK_ESCAPE) & 0x8000)
		{
			gameRun = false;
		}

		
		targetConsole->outputConsoleBuffer();
		
		Sleep(REFRESH_TIME);

	}



}