#include "Actor.h"
#include "Game.h"

Actor::Actor()
{
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
}

void Actor::AddComponent(Component* comp)
{
	m_comps.push_back(comp);
}
