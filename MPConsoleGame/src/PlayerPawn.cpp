#include <PlayerPawn.h>

PlayerPawn::PlayerPawn(ScreenManager* targetConsole, std::string pawnSprite, int posX, int posY, unsigned short startHealth, float playerSpeed, float refreshTime) :
	Pawn(targetConsole, pawnSprite, posX, posY)
{

	m_playerHealth = startHealth;
	m_playerSpeed = playerSpeed;
	m_refreshTime = refreshTime;

	m_posX = posX;
	m_posY = posY;

}

PlayerPawn::~PlayerPawn()
{



}

unsigned short PlayerPawn::getPlayerHealth()
{

	return m_playerHealth;

}

float PlayerPawn::getPlayerSpeed()
{

	return m_playerSpeed;

}

void PlayerPawn::setPlayerSpeed(float inputSpeed)
{

	m_playerSpeed = inputSpeed;

}

void PlayerPawn::setPlayerHealth(unsigned short inputHealth)
{

	m_playerHealth = inputHealth;

}

void PlayerPawn::playerMoveUp()
{



}

void PlayerPawn::playerMoveDown()
{



}

void PlayerPawn::playerMoveLeft()
{



}

void PlayerPawn::playerMoveRight()
{



}

