#include <LogSystem.h>
#include <windows.h>
#include <iostream>
#include <string.h>


/*
* @brief Constructer for Log
* 
* @param logDirectory
* 
* @param logFileName
*
*/


LogSystem::LogSystem(std::wstring logDirectory, std::string logFileName)
{
	if (logFileName == " " && logDirectory == L" ")
	{
		LPWSTR buffer = new WCHAR[256];
		
		GetCurrentDirectory(256, buffer);

		{
			int bufferIndex = 0;

			while (bufferIndex < 256)
			{

				logDirectory += *(buffer+bufferIndex);

				bufferIndex++;

			}

			std::wcout << logDirectory << "\n" << std::endl;
			   

		}

		delete[] buffer;

		logDirectory = logDirectory + L"GameLog";


		HANDLE windowsHandleFileFind;
		WIN32_FIND_DATAW fileData;

		windowsHandleFileFind = FindFirstFile( logDirectory.c_str(), &fileData);



		FindClose(windowsHandleFileFind);
	}
	/*else if ()
	{


	}
	*/

	
}



LogSystem::~LogSystem()
{



}
