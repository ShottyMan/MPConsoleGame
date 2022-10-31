#include <SpriteLoader.h>
#include <ConsoleMng.h>

ScreenGameObject::ScreenGameObject()
{

}

ScreenGameObject::~ScreenGameObject()
{

}

struct Sprite ScreenGameObject::loadSprite(std::string filePath)
{

	Sprite returnObject;

	std::fstream spriteFile;

	spriteFile.open(filePath, std::ios::out);

	pixelObj tempPixel;

	int count = 0;

	for (std::string inStringLine; std::getline(spriteFile, inStringLine);)
	{
		
		bool firstCharSeen = false;

		for (int size = 0; size < inStringLine.size(); ++size)
		{

				char temp = inStringLine.at(size);

				if (temp != ' ' && firstCharSeen == false) 
				{

					firstCharSeen = true;

					tempPixel = { size, count, temp };

					objComponets.push_back(tempPixel);


				}
				else if (firstCharSeen == true)
				{

					tempPixel = { size, count, temp };

					objComponets.push_back(tempPixel);

				}


		}


	}

	spriteFile.close();

	for (int index = 0; index < objComponets.size(); ++index)
	{

		returnObject.sprite.push_back(objComponets.at(index).pixel);
		returnObject.posX.push_back(objComponets.at(index).posX);
		returnObject.posY.push_back(objComponets.at(index).posY);


	}

	objComponets.clear();

	return returnObject;


}