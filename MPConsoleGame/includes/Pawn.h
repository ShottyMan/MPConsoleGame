#pragma once
#include <string>
#include <ScreenManager.h>
#include <LogSystem.h>

class Pawn
{

protected:

	std::string m_sprite;
	double m_posX;
	double m_posY;
	ScreenManager* m_tConsole;

public:

	Pawn(ScreenManager* /*Pointer to parent console*/, std::string /*Sprite*/, int posX, int posY, LogSystem*);
	~Pawn();

	//Moves pawn in each direction by the supplied values.
	void move(int x/*Transformation not placing*/, int y /*Transformation, not placing*/);
	//Sets the coordinates of the pawn to the suppplied ones.
	void place(int x, int y);
	//Changes the sprite of the pawn
	void setSprite(std::string pawnSprite);



};