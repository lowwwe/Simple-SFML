#ifndef GAME
#define GAME



#include <SFML/Graphics.hpp>




class Game
{
public:
	Game();
	void run();
private:
	void             processEvents();
	void             update(sf::Time);
	void             render();

private:        
	sf::RenderWindow m_window;
	sf::CircleShape  m_circle;
};

#endif // !GAME
