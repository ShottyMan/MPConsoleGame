#include <LogSystem.h>
#include <windows.h>
#include <iostream>
#include <string.h>
#include <ctime>
#include <sstream>
#include <iomanip>

/*
* @brief Constructer for Log
* 
* @param logDirectory
* 
* @param logFileName
*
*/


LogSystem::LogSystem(std::wstring logDirectory, std::wstring logFileName, std::wstring logDirName) //Constructer for the logger Class, it is used to find the directory and initialize the fstream.
{
	HANDLE windowsHandleFileFind;
	WIN32_FIND_DATAW fileData;

	/*
	* This section is made for filling in all of the variables that are not specified by the user 
	* of the specific class. 
	* 
	*/
	if (logFileName == L" " && logDirectory == L" ")
	{
		logFileName.clear();
		logDirectory.clear();

		LPWSTR buffer = new WCHAR[256];
		
		GetCurrentDirectory(256, buffer);

		{
			int bufferIndex = 0;

			while (bufferIndex < 256)
			{
				if (*(buffer + bufferIndex) == '\0')
				{

					break;

				}
				logDirectory += *(buffer+bufferIndex);

				bufferIndex++;

			}

			std::wcout << logDirectory << "\n" << std::endl;
			   

		}

		delete[] buffer;
		
		logDirectory.append(L"\\");
		logDirectory.append(logDirName);

		windowsHandleFileFind = FindFirstFile(logDirectory.c_str(), &fileData);
		std::time_t time = std::time(nullptr);

		if (windowsHandleFileFind == INVALID_HANDLE_VALUE)
		{

			std::cout << "\nUnable to find the folder, Error message: " << GetLastError() << "\nCreating new folder for log system. (Press Enter to continue)\n";
			std::cin.get();

			SetLastError(0);

			std::wcout << logDirectory.c_str() << std::endl;
			
			
			//tempNewDir.append(L"\\\\?\\");
			
			BOOL DirectoryCreationSuccess = CreateDirectory(logDirectory.c_str(), NULL);

			if(DirectoryCreationSuccess && time)
			{
				std::tm tm;
				
				//Added for debugging Reasons
				errno_t timeSuccess = localtime_s(&tm ,&time);

				//Convertion since string stream is only a regular string and not a wide string

				std::stringstream temp;

				temp << "Log-" << std::put_time(&tm, "%H-%M-%S--%m-%d-%Y") << ".txt";

				size_t stringLenght = sizeof(temp.str()) / sizeof(temp.str()[0]);

				std::wstring tempString(L"#", stringLenght);

				//&tempString[0], temp.str().c_str(), stringLenght;//

				size_t tempOutSize;

				mbstowcs_s(&tempOutSize, &tempString[0], stringLenght, temp.str().c_str(), stringLenght);

				LogSystem::logFileName = tempString;
			
			}
			else
			{
				std::cout << "Directory creation Error: " << GetLastError() << " writting log in base directory (Press Enter to continue)" << std::endl;
				std::cin.get();
				SetLastError(0);

			}

		}
		else if (time)
		{
			std::tm tm;

			//Added for debugging Reasons
			errno_t timeSuccess = localtime_s(&tm, &time);

			//Convertion since string stream is only a regular string and not a wide string

			std::stringstream temp;

			temp << "Log-" << std::put_time(&tm, "%H-%M-%S--%m-%d-%Y") << ".txt";

			size_t stringLenght = sizeof(temp.str()) / sizeof(temp.str()[0]);

			std::wstring tempString(L"#", stringLenght);

			size_t tempOutSize;

			mbstowcs_s(&tempOutSize, &tempString[0], stringLenght, temp.str().c_str(), stringLenght);

			LogSystem::logFileName = tempString;


		}



		FindClose(windowsHandleFileFind);
	}
	/*else if ()
	{


	}
	*/

	LogSystem::logFileDirectory = logDirectory + L"\\";
	LogSystem::logFileDirectory.append(LogSystem::logFileName);

	LogSystem::logFile.open(LogSystem::logFileDirectory, std::ios::out);
	
}



LogSystem::~LogSystem()
{

	LogSystem::logFile.close();

}

void LogSystem::WriteLine(std::wstring inputString, logLevels messageType)
{
	std::stringstream timeString;

	std::time_t time = std::time(nullptr);
	std::tm tm;
	errno_t timeSuccess = localtime_s(&tm, &time);

	timeString << std::put_time(&tm, "(%H:%M:%S)");

	size_t stringLenght = timeString.str().size() + 1;

	std::wstring outString(L"#", stringLenght);

	size_t tempOutSize;

	mbstowcs_s(&tempOutSize, &outString[0], stringLenght, timeString.str().c_str(), stringLenght);


	outString[stringLenght - 1] = L' ';
	


	switch (messageType)
	{
	case LVL_INFO:
		outString += L"- [INFO]: ";
		outString += inputString;
		LogSystem::logFile << outString << std::endl;
		break;
	case LVL_ERROR:
		outString += L"- [ERROR]: ";
		outString += inputString;
		LogSystem::logFile << outString << std::endl;
		break;
	case LVL_WARNING:
		outString += L"- [WARNING]: ";
		outString += inputString;
		LogSystem::logFile << outString << std::endl;
		break;
	case LVL_CATASTROPHIC:
		outString += L"- [CATASTROPIC!!!!]: ";
		outString += inputString;
		LogSystem::logFile << outString << std::endl;
		break;
	}
}