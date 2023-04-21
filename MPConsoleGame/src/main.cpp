#include <ScreenManager.h>
#include <chrono>
#include <stdlib.h>
#include <Menus.h>
#include <SinglePlayer.h>
#include <LogSystem.h>




int main()
{
	LogSystem LogSystem(L"C:\\Users\\Ekha7\\Desktop\\logFiles", L"TestName");

	//mainMenu();

	//ScreenManager console;

	//singlePlayerGame(&console);

	//mainMenu();

	LogSystem.WriteLine(L"TestLog");
	
	std::cout << "Game has ended I hope you enjoyed!" << std::endl;

	return 0;

}