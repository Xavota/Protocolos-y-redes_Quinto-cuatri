#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Component.h"

class Actor
{
public:
	Actor();
	Actor(sf::Vector2f pos);
	~Actor();
	void Init();
	void Update();
	void Render();
	void Destroy();

	void AddComponent(Component* comp);
	sf::Vector2f getPosition() { return m_pos; }
	void setPosition(sf::Vector2f newPos) { m_pos = newPos; }
	template<class T> 
	T* getComponent();
	//Component* getComponent();
private:
	friend class Component;
	friend class Movimiento;
	friend class Mesh;
	friend class Game;
	std::vector<Component*> m_comps;
	sf::Vector2f m_pos;
};

