#include "stdafx.h"
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES



class Game 
{
public:
	Game();
	void run();
private:        
	void             processEvents(); 
	void             update(sf::Time); 
	void             render();

private:        sf::RenderWindow m_window;        
				sf::CircleShape  m_circle;
}; 
int main(int argc, _TCHAR* argv[])
{ 
	Game game; 
	game.run(); 
}
Game::Game() : m_window(sf::VideoMode(800, 480), "SMFL Game"), m_circle()
{
	m_circle.setRadius(40.f);
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