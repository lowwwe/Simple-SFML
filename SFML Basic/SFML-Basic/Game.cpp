

#include "Game.h"


Game::Game() 
	: m_window{ sf::VideoMode{800, 480}, "SMFL Game" },
	m_circle{40.0f}
{	
	m_circle.setPosition(100.f, 100.f);
	m_circle.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{		
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);			
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();

		}
	}
}

void Game::update(sf::Time)
{

}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_circle);
	m_window.display();
}