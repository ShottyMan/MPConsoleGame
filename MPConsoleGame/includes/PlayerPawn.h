#pragma once
#include <Pawn.h>
#include <LogSystem.h>

class PlayerPawn : Pawn {

private:

	unsigned short m_playerHealth;
	float m_playerSpeed;
	float m_refreshTime;

public:

	PlayerPawn(ScreenManager* targetConsole, std::string pawnSprite, int posX, int posY, unsigned short startHealth, float playerSpeed, unsigned int refreshTime, LogSystem*);
	~PlayerPawn();
	
	float getPlayerSpeed();
	unsigned short getPlayerHealth();
	void setPlayerSpeed(float input);
	void setPlayerHealth(unsigned short input);

	void playerMoveUp();
	void playerMoveDown();
	void playerMoveLeft();
	void playerMoveRight();


};