#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenSize.h"

class Cutscene
{
public:
	Cutscene();
	void init(sf::Font& t_font);
	void draw(sf::RenderWindow& t_window);
	bool update();
private:

	static const int MAX_INTRO = 8;
	sf::Texture m_bgTexture;
	sf::Sprite m_bgSprite;
	sf::Texture m_blackOutTexture;
	sf::Sprite m_blackOutSprite;
	sf::Texture m_robotTexture;
	sf::Sprite m_robotSprite;
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	std::string m_introText[MAX_INTRO];

	sf::Text m_intro[MAX_INTRO];
};


