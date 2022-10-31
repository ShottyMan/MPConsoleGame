#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct pixelObj
{

	int posX;
	int posY;

	char pixel;

};

class ScreenGameObject
{
private:
	std::vector<pixelObj> objComponets;


public:
	ScreenGameObject();
	~ScreenGameObject();

	struct Sprite loadSprite(std::string filePath);

};