#include "Game.h"
#include "Globals.h"
#include "Movimiento.h"
#include "Mesh.h"


sf::RenderWindow* Game::m_window;
sf::CircleShape Game::m_shape;
sf::Time Game::timePerFrame = sf::seconds(1.f / 60.f);
Actor* Game::m_actor = nullptr;
sf::RectangleShape Game::m_map;

Game::~Game()
{
}

Game::Game()
{
}

void Game::run()
{
	init();

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_window->isOpen())
	{
		processEvents();

		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate >= timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			gl::DeltaTime::m_time = timePerFrame.asSeconds();
			update();
			Input::Update();
		}
		render();
	}

	destroy();
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			Input::HandleInputs(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			Input::HandleInputs(event.key.code, false);
			break;
		case sf::Event::Closed:
			m_window->close();
			break;
		}
	}
}

void Game::init()
{
	m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Chess");

	CTexture::AddTexture("Amongos rojo", "amongs_rojo.png");
	CTexture::AddTexture("Mapa", "Mapa.jpg");

	m_map.setTexture(CTexture::getTexture("Mapa"));
	m_map.setSize((sf::Vector2f)CTexture::getTexture("Mapa")->getSize() * 3.5f);
	m_map.setPosition({ -2000,-2000 });

	m_actor = new Actor();
	m_actor->AddComponent(new Movimiento(200.f));
	//m_actor->AddComponent(new Mesh((sf::Vector2f)CTexture::getTexture("Amongos rojo")->getSize() * .16f,CTexture::getTexture("Amongos rojo")));
	m_actor->Init();
	m_actor->getComponent<Movimiento>();
}

void Game::update()
{
	m_actor->Update();

	m_window->setView(sf::View({ m_actor->m_pos }, {1920,1080}));
}

void Game::render()
{
	m_window->clear();
	m_window->draw(m_map);
	m_actor->Render();
	m_window->display();
}

void Game::destroy()
{
}