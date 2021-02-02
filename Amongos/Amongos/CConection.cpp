#include "CConection.h"

CConection::CConection()
{
	m_listener.listen(50000, "127.0.0.1");
}

CConection::~CConection()
{
}

void CConection::SendMessage(Message msg)
{
	sf::Packet packet;
	packet << msg.velx << msg.vely;
	m_socket.send(packet);
}

Message CConection::ReciveMessage()
{
	sf::Packet packet;
	m_socket.receive(packet);
	Message msg;
	packet >> msg.velx >> msg.vely;
	return msg;
}
