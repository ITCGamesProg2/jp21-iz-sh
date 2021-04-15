#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenSize.h"
class AI
{
public:
	AI() {};
	void init();
	void draw(sf::RenderWindow& t_window);
	void update();

	sf::Sprite getSprite() {
		return m_enemySprite;
	}
	
	void dealDamage()
	{
		m_health = m_health - 34;
	}

private:
	sf::Texture m_enemyTexture;
	sf::Sprite m_enemySprite;
	int m_health = 100;
	bool m_alive = true;
};
