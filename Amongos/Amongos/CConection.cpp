#include "CConection.h"

CConection::CConection()
{
	m_socket.setBlocking(false);
}

CConection::~CConection()
{
}

bool CConection::MakeConection(unsigned const short& port)
{
	m_port = port;
	return m_socket.bind(m_port) != sf::Socket::Done;
}

void CConection::SendMessage(Message msg, sf::IpAddress adress, const unsigned short& port)
{
	sf::Packet packet;
	packet << msg.velx << msg.vely;
	m_socket.send(packet, adress, port);
}

sf::Socket::Status CConection::ReciveMessage(Message& msg, sf::IpAddress& senderAdress, unsigned short& senderPort)
{
	sf::Packet packet;
	sf::Socket::Status reciveStatus = m_socket.receive(packet, senderAdress, senderPort);
	packet >> msg.velx >> msg.vely;
	return reciveStatus;
}
