#include <ScreenManager.h>
#include <chrono>
#include <stdlib.h>
#include <Menus.h>
#include <SinglePlayer.h>





int main()
{
	//mainMenu();

	ScreenManager console;

	singlePlayerGame(&console);
	
	std::cout << "Game has ended I hope you enjoyed!" << std::endl;

}