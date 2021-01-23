#include "Movimiento.h"
#include "Globals.h"
#include "Actor.h"

void Movimiento::Update(Actor* actor)
{
	sf::Vector2f mov;
	if (Input::GetKey(sf::Keyboard::A))
		mov += sf::Vector2f(-1, 0);
	if (Input::GetKey(sf::Keyboard::D))
		mov += sf::Vector2f(1, 0);
	if (Input::GetKey(sf::Keyboard::W))
		mov += sf::Vector2f(0, -1);
	if (Input::GetKey(sf::Keyboard::S))
		mov += sf::Vector2f(0, 1);

	actor->m_pos += mov * m_speed * gl::DeltaTime::Time();
}
