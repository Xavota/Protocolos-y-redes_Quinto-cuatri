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

	Message ReciveMessage();
	void SendMessage(Message msg);

private:
	sf::TcpSocket m_socket;
	sf::TcpListener m_listener;
};

