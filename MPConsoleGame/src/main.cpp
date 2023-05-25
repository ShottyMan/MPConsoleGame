#include <ScreenManager.h>
//#include <chrono>
//#include <stdlib.h>
#include <Menus.h>
#include <SinglePlayer.h>
#include <LogSystem.h>




int main()
{
	LogSystem LogSystem;

	//mainMenu();

	LogSystem.WriteLine(L"Game Started!");


	ScreenManager console;

	singlePlayerGame(&console);


	
	
	std::cout << "Game has ended I hope you enjoyed!" << std::endl;

	return 0;

}