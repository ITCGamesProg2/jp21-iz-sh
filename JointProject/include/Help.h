#pragma once
#include <SFML\Graphics.hpp>
#include "ScreenSize.h"
#include "Player.h"

class HelpScreen
{

private:

	sf::String m_helpTextString;
	sf::Text m_helpText;
	sf::Font m_font;
	sf::Sprite m_controlsSprite;
	sf::Texture m_controlsTexture;

	sf::Sprite m_background;
	sf::Texture m_backgroundTexture;

	sf::Texture m_buttonTexture;
	sf::Sprite m_buttonSprite;

	sf::Vector2f m_originalPos;
	sf::Vector2f m_pushedDownPos;

	sf::Text m_exitText;

public:

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window); //draws the sprites and texts
	bool update(sf::Window& t_window);

};