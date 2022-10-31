#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>
#include <SpriteLoader.h>

typedef std::vector<std::vector<char>> consoleBuffer;
typedef std::vector<char> vecChar;


struct consoleDimensions {

	int columns;
	int rows;
};

struct Sprite {

	std::string sprite;
	std::vector<int> posX;
	std::vector<int> posY;

};

class ConsoleManager
{

private:
	//Console Buffer and Dimensions in rows and columns.
	consoleDimensions m_cDimensions;
	consoleBuffer m_cBuffer;
	ScreenGameObject m_gameLoader;
	std::vector<Sprite> m_gameObjectID;

public:

	std::vector<Sprite> gameObjectsLoaded;
	
	ConsoleManager();
	~ConsoleManager();

	void getConsoleSize();

	void initializeConsoleBuffer();

	void placeGameObject(int posX, int posY, int objectID);

	void printConsoleBuffer();
};
