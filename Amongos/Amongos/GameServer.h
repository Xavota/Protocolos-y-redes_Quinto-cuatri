#pragma once
#include <SFML/Network.hpp>
class GameServer
{
public:
	GameServer();
	~GameServer();

	void Init();
	void Update();
	void Render();

	void UpdateLogic();

	void Loop();

	void ExecutionThread();

	void HandleIncomingPackets();
	void HandleIncomingConnections();

	void shutdown();

private:
	bool m_timeToStop = false;

	sf::Time m_stepTime;
	sf::Time m_stepInterval;

	sf::Time m_tickTime;
	sf::Time m_tickInterval;
};

