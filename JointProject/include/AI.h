#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenSize.h"
#include <time.h>
#include "ParticalEffects.h"
#include "Grid.h"

class AI
{
public:
	AI() {
		std::srand(time(NULL));
	};
	void init(Grid &t_grid);
	void draw(sf::RenderWindow& t_window);
	void update(Grid& m_grid);

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

	void nextCell()
	{
		int nextCell = m_aiPath.at(m_aiPath.size() - 1);

	}

private:
	sf::Texture m_enemyTexture;
	sf::Sprite m_enemySprite;
	sf::CircleShape m_rangeCircle;

	int m_health = 100;
	int m_bulletDamage = 34;
	bool m_alive = true;
	int randCell;
	int randY;

	std::vector<int> m_aiPath;

	bool m_shootingAtPlayer = false;

};

