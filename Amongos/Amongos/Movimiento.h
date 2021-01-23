#pragma once
#include "Component.h"
class Movimiento : public Component
{
public:
	Movimiento(float speed) { m_speed = speed; }
	~Movimiento() {}
	void Update(Actor* actor);
private:
	float m_speed;
};

