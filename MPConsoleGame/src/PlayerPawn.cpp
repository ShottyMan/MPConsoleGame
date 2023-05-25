#include <PlayerPawn.h>
#include <LogSystem.h>

PlayerPawn::PlayerPawn(ScreenManager* targetConsole, std::string pawnSprite, int posX, int posY, unsigned short startHealth, float playerSpeed, unsigned int refreshTime, LogSystem* logClass) : Pawn(targetConsole, pawnSprite, posX, posY, LogClass)
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

	m_posY = m_posY + (m_refreshTime * m_playerSpeed);

	move(m_posX, m_posY);

}

void PlayerPawn::playerMoveDown()
{

	m_posY = m_posY - (m_refreshTime * m_playerSpeed);

	move(m_posX, m_posY);

}

void PlayerPawn::playerMoveLeft()
{

	m_posX = m_posX - (m_refreshTime * m_playerSpeed);

	move(m_posX, m_posY);

}

void PlayerPawn::playerMoveRight()
{

	m_posX = m_posX + (m_refreshTime * m_playerSpeed);

	move(m_posX, m_posY);

}

