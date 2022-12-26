#include <Pawn.h>

Pawn::Pawn(ScreenManager* targetConsole, std::string pawnSprite, int posX, int posY)
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
	m_tConsole->stringDelToConsole(m_sprite, m_posX, m_posY);

	m_posX += x;
	m_posY += y;

	m_tConsole->stringToConsole(m_sprite, x, y);

}

void Pawn::place(int x, int y)
{
	m_tConsole->stringDelToConsole(m_sprite, m_posX, m_posY);

	m_posX = x;
	m_posY = y;

	int currentColumn = 0;

	m_tConsole->stringToConsole(m_sprite, x, y);

}