#include <Pawn.h>



Pawn::Pawn(ScreenManager* targetConsole, std::string pawnSprite, int posX, int posY, LogSystem* LogClass)
{

	m_tConsole = targetConsole;
	m_sprite = pawnSprite;

}

Pawn::~Pawn()
{



}

void Pawn::setSprite(std::string pawnSprite)
{

	m_sprite = pawnSprite;

}

void Pawn::move(int x, int y)
{
	std::stringstream ss;

	m_tConsole->stringDelToConsole(m_sprite, m_posX, m_posY);

	m_posX += x;
	m_posY += y;

	int integerX = (int)floor(m_posX);
	int integerY = (int)floor(m_posY);

	m_tConsole->stringToConsole(m_sprite, integerX, integerY);

}

void Pawn::place(int x, int y)
{
	m_tConsole->stringDelToConsole(m_sprite, m_posX, m_posY);

	m_posX = x;
	m_posY = y;

	//Not sure why this was here I am keeping it just in case...
	//int currentColumn = 0;

	int integerX = (int)floor(m_posX);
	int integerY = (int)floor(m_posY);

	m_tConsole->stringToConsole(m_sprite, integerX, integerY);

}