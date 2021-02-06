#include "CNetworkManager.h"

CNetworkManager::CNetworkManager(bool isServer, const unsigned short& port)
{
	Init(isServer, port);
}

void CNetworkManager::Init(bool isServer, const unsigned short& port)
{
	m_isServer = isServer;
	m_port = port;
}

void CNetworkManager::Start()
{
	if (m_isServer){
		if (m_conection.MakeConection(m_port))
		{
			cout << "error tring to conect to port " << m_port << endl;
		}
		else
		{
			m_serverOpen = true;

			m_networkThread = std::make_shared<thread>(std::bind(&CNetworkManager::NetworkThread, this));
		}
	}
	else
	{
		m_serverOpen = true;
		m_networkThread = std::make_shared<thread>(std::bind(&CNetworkManager::NetworkThread, this));
	}
}

//Cartero
void CNetworkManager::NetworkThread()
{
	while(m_serverOpen){
		if (m_isServer)
		{
			sf::IpAddress SenderAdress;
			unsigned short SenderPort;
			Message SenderMsg;

			if (m_conection.ReciveMessage(SenderMsg, SenderAdress, SenderPort) == sf::Socket::NotReady)
			{
				cout << "Not bytes recived" << endl;
			}
			else
			{
				cout << "Recived (" << SenderMsg.velx << ", " << SenderMsg.vely << ") from IP: " << SenderAdress << ", port: " << SenderPort << endl;
			}
		}
		else
		{
			m_conection.SendMessage({ 100,100 }, "127.0.0.1", m_port);
			cout << "Send (" << 100 << ", " << 100 << ") to IP: " << "127.0.0.1" << ", port: " << m_port << endl;
		}
	}
}

void CNetworkManager::CloseServer()
{
	m_serverOpen = false;
}

void CNetworkManager::Destroy()
{
	CloseServer();
}
