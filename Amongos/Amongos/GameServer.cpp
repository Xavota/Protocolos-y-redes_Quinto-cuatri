#include "GameServer.h"

GameServer::GameServer()
{
}

GameServer::~GameServer()
{
}

void GameServer::Init()
{
}

void GameServer::Update()
{
}

void GameServer::Render()
{
}

void GameServer::UpdateLogic()
{
}

void GameServer::Loop()
{
	HandleIncomingPackets();
	HandleIncomingConnections();
	while (m_stepTime >= m_stepInterval)
	{
		UpdateLogic();
		m_stepTime -= m_stepInterval;
	}
	while (m_tickTime >= m_tickInterval)
	{
		Update();
		m_tickTime -= m_tickInterval;
	}
	sf::sleep(sf::milliseconds(50));
}

void GameServer::ExecutionThread()
{
	Init();
	while (!m_timeToStop) Loop();
	shutdown();
}

void GameServer::HandleIncomingPackets()
{
}

void GameServer::HandleIncomingConnections()
{
}

void GameServer::shutdown()
{
}
