#include <LogSystem.h>
#include <windows.h>
#include <iostream>
#include <string.h>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <iomanip>


std::wstring createLogName(time_t* inTime, std::string inputString = "Log")
{
	std::tm tm;

	//Added for debugging Reasons

	time(inTime);

	errno_t timeSuccess = localtime_s(&tm, inTime);
	// 
	//Convertion since string stream is only a regular string and not a wide string

	std::stringstream temp;

	temp << inputString << std::put_time(&tm, "-%H-%M-%S--%m-%d-%Y") << ".txt";

	size_t stringLenght = sizeof(temp.str()) / sizeof(temp.str()[0]);

	std::wstring tempString(L"#", stringLenght);

	//&tempString[0], temp.str().c_str(), stringLenght;//

	size_t tempOutSize;

	mbstowcs_s(&tempOutSize, &tempString[0], stringLenght, temp.str().c_str(), stringLenght);

	return tempString;

}

void LogDirCreation(std::wstring LogDirectory, time_t *inTime, std::wstring *LogDirectoryFileName)
{

	time(inTime);

	BOOL DirectoryCreationSuccess = CreateDirectory(LogDirectory.c_str(), NULL);

	if (DirectoryCreationSuccess && *inTime)
	{


		*LogDirectoryFileName = createLogName(inTime);

	}
	else
	{
		std::cout << "Directory creation Error: " << GetLastError() << " writting log in base directory (Press Enter to continue)" << " or an error initializing the time." << std::endl;
		std::cin.get();
		SetLastError(0);

	}

}

std::wstring RetreivingCWD(std::wstring outDirectory, std::wstring inputDirectoryName)
{

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
			outDirectory += *(buffer + bufferIndex);

			bufferIndex++;

		}

		std::wcout << outDirectory << "\n" << std::endl;


	}

	delete[] buffer;

	outDirectory.append(L"\\");
	outDirectory.append(inputDirectoryName);

}

std::wstring TimeString()
{

	std::stringstream timeString;

	std::time_t timeType;

	time(&timeType);

	std::tm tm;

	errno_t timeSuccess = localtime_s(&tm, &timeType);
	
	timeString << std::put_time(&tm, "(%H:%M:%S)");

	size_t stringLenght = timeString.str().size() + 1;

	std::wstring outString(L"#", stringLenght);

	size_t tempOutSize;

	mbstowcs_s(&tempOutSize, &outString[0], stringLenght, timeString.str().c_str(), stringLenght);


	outString[stringLenght - 1] = L' ';

	return outString;

}

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

	windowsHandleFileFind = FindFirstFile(logDirectory.c_str(), &fileData);
	std::time_t time;

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

		if (windowsHandleFileFind == INVALID_HANDLE_VALUE)
		{

			std::cout << "\nUnable to find the folder, Error message: " << GetLastError() << "\nCreating new folder for log system. (Press Enter to continue)\n";
			std::cin.get();

			SetLastError(0);

			//For debug purposes
			//std::wcout << logDirectory.c_str() << std::endl;
			
			LogDirCreation(logDirectory, &time, &logDirName);

		}
		else
		{

			LogSystem::logFileName = createLogName(&time);

		}


		FindClose(windowsHandleFileFind);
	}
	else if (logFileName == L" ")
	{

		LogDirCreation(logDirectory, &time, &logDirName);

	}
	else if (logDirectory == L" ")
	{


	}
	else
	{


	}


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
	
	
	std::wstring outString = TimeString();

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