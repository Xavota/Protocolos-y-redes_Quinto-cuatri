#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include "GameServer.h"

class MultiplayerGameState
{
public:
	MultiplayerGameState(bool isHost);
	virtual bool Update();
	virtual void Render();
private:
	void updateBroadcastMessage(
		sf::Time elapsedTime);
	void handlePacket(sf::Int32 packetType,
		sf::Packet& packet);
private:
	//typedef std::unique_ptr<Player> PlayerPtr;
private:
	sf::RenderWindow& mWindow;
	//std::map<int, PlayerPtr> m_players;
	std::vector<sf::Int32> mLocalPlayerIdentifiers;
	sf::TcpSocket mSocket;
	bool mConnected;
	std::unique_ptr<GameServer> mGameServer;
	sf::Clock mTickClock;
	std::vector<std::string> mBroadcasts;
	sf::Text mBroadcastText;
	sf::Time mBroadcastElapsedTime;
};

