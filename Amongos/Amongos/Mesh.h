#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
class Mesh : public Component
{
public:
	Mesh(sf::Vector2f size, sf::Color color);
	Mesh(sf::Vector2f size, sf::Texture* texture);
	~Mesh();
	void Update(Actor* actor);
	void Render(Actor* actor);
private:
	sf::RectangleShape m_shape;
};

