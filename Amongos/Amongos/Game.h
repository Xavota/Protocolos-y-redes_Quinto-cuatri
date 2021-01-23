#pragma once
#include <SFML/Graphics.hpp>
#include "Actor.h"

class Game
{
public:
	static void run();

	static sf::RenderWindow* getWindow() { return m_window; }

	~Game();
private:
	Game();

	static void init();
	static void update();
	static void processEvents();
	static void render();
	static void destroy();

private:
	static sf::RenderWindow* m_window;

	static sf::CircleShape m_shape;

	static sf::Time timePerFrame;

	static Actor* m_actor;
	static sf::RectangleShape m_map;
};

