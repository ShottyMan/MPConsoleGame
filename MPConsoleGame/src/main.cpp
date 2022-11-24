#include <ScreenManager.h>
#include <chrono>
#include <stdlib.h>
#include <Menus.h>
#include <SinglePlayer.h>




//investigate this further
//https://stackoverflow.com/questions/3471520/how-to-remove-scrollbars-in-console-windows-c





int main()
{
	//mainMenu();

	ScreenManager console;

	singlePlayerGame(&console);
	
	std::cout << "Game has ended I hope you enjoyed!" << std::endl;

}