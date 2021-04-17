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

	/// <summary>
	/// returns the enemy sprite
	/// </summary>
	/// <returns></returns>
	sf::Sprite getSprite() {
		return m_enemySprite;
	}
	
	/// <summary>
	/// takes away health
	/// </summary>
	void dealDamage()
	{
		m_health = m_health - m_bulletDamage;
	}

	/// <summary>
	/// returns whether enemy is alive
	/// </summary>
	/// <returns></returns>
	bool isAlive()
	{
		return m_alive;
	}
private:
	sf::Texture m_enemyTexture;
	sf::Sprite m_enemySprite;
	int m_health = 100;
	int m_bulletDamage = 34;
	bool m_alive = true;
};
