#pragma once
#include <string>


class LogSystem
{

private:

	std::wstring logDirectory;
	std::string logFileName;

public:

	LogSystem(std::wstring logDirectory = L" ", std::string logFileName = " ");
	~LogSystem();



};
