#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenSize.h"
#include <time.h>

class AI
{
public:
	AI() {
		std::srand(time(NULL));
	};
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

	bool getShootingAtPlayer()
	{
		return m_shootingAtPlayer;
	}

	void setShootingAtPlayer(bool shootingAtPlayerStatus)
	{
		m_shootingAtPlayer = shootingAtPlayerStatus;
	}

	void setOutlineColor(sf::Color color)
	{
		m_rangeCircle.setOutlineColor(color);
	}

	void setScaleSprite(int scale)
	{
		m_enemySprite.setScale(scale, 1);
	}
	float m_spotPlayerRange = 200;

private:
	sf::Texture m_enemyTexture;
	sf::Sprite m_enemySprite;
	sf::CircleShape m_rangeCircle;

	int m_health = 100;
	int m_bulletDamage = 34;
	bool m_alive = true;
	int randX;
	int randY;

	bool m_shootingAtPlayer = false;
};

