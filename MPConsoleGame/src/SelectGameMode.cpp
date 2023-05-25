#include <SelectGameMode.h>
#include <Menus.h>

void selectGameMode(ScreenManager* targetConsole, LogSystem* logClass)
{

	targetConsole->clearBuffer();

	targetConsole->stringToConsole("Choose Game mode!!!", 4, 40);

	targetConsole->stringToConsole("Single Player\n\n"
		"Multiplayer", 10, 35);
	
	bool isChoosing = true;
	unsigned short selection = 0;

	while (isChoosing)
	{

		if (GetKeyState(VK_UP) & 0x8000)
		{

			targetConsole->placePixel(10, 34, '-');
			targetConsole->placePixel(12, 34, ' ');
			selection = 1;

		}
		else if (GetKeyState(VK_DOWN) & 0x8000)
		{

			targetConsole->placePixel(10, 34, ' ');
			targetConsole->placePixel(12, 34, '-');
			selection = 2;

		}

		if (GetKeyState(VK_RETURN) & 0x8000)
		{
		
			switch (selection)
			{

			case 1:
				break;
			case 2:

				break;

			}
		
		}

		targetConsole->outputConsoleBuffer();

		Sleep(REFRESH_TIME);

		clearScreen();

	}

}
