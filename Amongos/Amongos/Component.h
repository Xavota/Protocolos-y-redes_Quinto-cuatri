#pragma once
#include <SFML/Graphics.hpp>

class Actor;
class Component
{
public:
	Component() {};
	~Component() {};
	virtual void Update(Actor* actor) {};
	virtual void Render(Actor* actor) {};
private:
};

