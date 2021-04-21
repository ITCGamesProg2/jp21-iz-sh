#include <SFML\Graphics.hpp>
#include "ScreenSize.h"

class GameOverScreen
{

private:

	sf::String m_gameOverString;
	sf::Text m_gameOverText;
	sf::Font m_font;

	sf::Sprite m_background;
	sf::Texture m_backgroundTexture;

	sf::Texture m_buttonTexture;
	sf::Sprite m_buttonSprite;

	sf::Vector2f m_originalPos;
	sf::Vector2f m_pushedDownPos;

	sf::Text m_exitText;

public:

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	bool processInput(sf::Window& t_window, sf::Event t_event);
	void update(sf::Window& t_window, bool t_win);

};
