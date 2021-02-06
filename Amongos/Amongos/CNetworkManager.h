#pragma once
#include <SFML/Network.hpp>
#include "CConection.h"
#include <thread>
#include <memory>
#include <iostream>
#include <string>
#include <mutex>
#include <memory>
#include <functional>

using std::thread;
using std::mutex;
using std::shared_ptr;
using std::lock;
using std::cout;
using std::endl;

enum class Roll
{
	NONE = -1, SIMULATED_PROXY, AUTONOM_PROXY, AUTORITY
};

class CNetworkManager
{
public:
	CNetworkManager() = default;
	CNetworkManager(bool isServer, const unsigned short& port);
	~CNetworkManager() = default;
	void Init(bool isServer, const unsigned short& port);
	void Start();
	void NetworkThread();
	void CloseServer();
	void Destroy();

private:
	//Roll m_roll;
	CConection m_conection;
	shared_ptr<thread> m_networkThread;
	mutex m_mutexMsgList;

	bool m_serverOpen = true;

	bool m_isServer;
	unsigned short m_port;
};

