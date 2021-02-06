#pragma once
#include <SFML/Network.hpp>
#include <vector>

struct Message 
{
	float velx;
	float vely;
};

class CConection
{
public:
	CConection();
	~CConection();

	bool MakeConection(const unsigned short& port);
	void SendMessage(Message msg, sf::IpAddress adress, const unsigned short& port);
	sf::Socket::Status ReciveMessage(Message& msg, sf::IpAddress& senderAdress, unsigned short& senderPort);

private:
	friend class CNetworkManager;
	sf::UdpSocket m_socket;
	unsigned short m_port;
};

