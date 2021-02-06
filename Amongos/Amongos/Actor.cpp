#include "Actor.h"
#include "Game.h"
#include "Movimiento.h"
#include "Mesh.h"

Actor::Actor()
{
}

Actor::Actor(sf::Vector2f pos)
{
	m_pos = pos;
}

Actor::~Actor()
{
}

void Actor::Init()
{
}

void Actor::Update()
{
	for (int i = 0; i < m_comps.size(); i++) 
	{
		m_comps[i]->Update(this);
	}
}

void Actor::Render()
{
	for (int i = 0; i < m_comps.size(); i++)
	{
		m_comps[i]->Render(this);
	}
}

void Actor::Destroy()
{
	for (Component* comp : m_comps)
	{
		if (comp != nullptr)
		{
			delete comp;
			comp = nullptr;
		}
	}
	m_comps.clear();
}

void Actor::AddComponent(Component* comp)
{
	m_comps.push_back(comp);
}

template<class T>
T* Actor::getComponent()
//Component* Actor::getComponent()
{
	for (int i = 0; i < m_comps.size(); i++) {
		if (dynamic_cast<T*>(m_comps[i]))
			std::cout << "si" << std::endl;
	}
	return nullptr;
}