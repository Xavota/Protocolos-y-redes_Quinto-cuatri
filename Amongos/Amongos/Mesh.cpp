#include "Mesh.h"
#include "Globals.h"

Mesh::Mesh(sf::Vector2f size, sf::Color color)
{
	m_shape.setSize(size);
	m_shape.setFillColor(color);
	m_shape.setOrigin(m_shape.getSize() * .5f);
}

Mesh::Mesh(sf::Vector2f size, sf::Texture* texture)
{
	m_shape.setSize(size);
	m_shape.setTexture(texture);
	m_shape.setOrigin(m_shape.getSize() * .5f);
}

Mesh::~Mesh()
{
}

void Mesh::Update(Actor* actor) 
{
	m_shape.setPosition(actor->m_pos);
}

void Mesh::Render(Actor* actor)
{
	Game::getWindow()->draw(m_shape);
}
