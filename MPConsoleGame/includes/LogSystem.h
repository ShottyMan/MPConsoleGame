#pragma once
#include <string>
#include <fstream>

enum logLevels{

	LVL_INFO, LVL_WARNING, LVL_ERROR, LVL_CATASTROPHIC

};

class LogSystem
{

private:

	std::wstring logDirectory;
	std::wstring logFileName;
	std::wstring logFileDirectory;
	std::wfstream logFile;

public:

	

	LogSystem(std::wstring logDirectory = L" ", std::wstring logFileName = L" ", std::wstring logDirName = L"Logs");
	void WriteLine(std::wstring inputString, logLevels messageType = logLevels::LVL_INFO);
	~LogSystem();



};
