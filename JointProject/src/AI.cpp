#include "AI.h"

void AI::init()
{
	if (!m_enemyTexture.loadFromFile("./resources/enemy.png"))
	{
		std::string s("Error loading enemy sprite");
		throw std::exception(s.c_str());
	}
	m_enemySprite.setTexture(m_enemyTexture);
	m_enemySprite.setOrigin(m_enemySprite.getGlobalBounds().width / 2, m_enemySprite.getGlobalBounds().height / 2);

	//m_enemySprite.setPosition(ScreenSize::s_width / 2, m_enemySprite.getGlobalBounds().height / 2);

	// positions to test where the AI will shoot its bullet
	m_enemySprite.setPosition(900, 200);
}

void AI::draw(sf::RenderWindow& t_window)
{
	if (m_alive)
	{
		t_window.draw(m_enemySprite);
	}
}

void AI::update()
{
	if (m_health <= 0)
	{
		m_alive = false;
	}
}
