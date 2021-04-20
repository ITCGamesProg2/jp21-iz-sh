#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ScreenSize.h"

class HUD
{
public:

	HUD();

	void init(sf::Font& t_font);

	void update(Player &t_player);

	void draw(sf::RenderWindow & window);

private:
	// The font for this HUD.

	sf::Text m_hiddenStatusText;

	sf::Text m_ammoCounterText;

	sf::Text m_gunStatusText;

};