#include "AI.h"

void AI::init()
{
	if (!m_enemyTexture.loadFromFile("./resources/robot.png"))
	{
		std::string s("Error loading enemy sprite");
		throw std::exception(s.c_str());
	}
	m_enemySprite.setTexture(m_enemyTexture);
	m_enemySprite.setOrigin(m_enemySprite.getGlobalBounds().width / 2, m_enemySprite.getGlobalBounds().height / 2);

	//m_enemySprite.setPosition(ScreenSize::s_width / 2, m_enemySprite.getGlobalBounds().height / 2);

	// positions to test where the AI will shoot its bullet
	m_enemySprite.setPosition(900, 200);
	randX = std::rand() % (ScreenSize::s_width - 200) + 100;
	randY = std::rand() % (ScreenSize::s_height - 200) + 100;
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

	if (m_enemySprite.getPosition().x == randX && m_enemySprite.getPosition().y == randY)
	{
		randX = std::rand() % (ScreenSize::s_width - 200) + 100;
		randY = std::rand() % (ScreenSize::s_height - 200) + 100;
	}

	if (m_enemySprite.getPosition().x > randX)
	{
		m_enemySprite.move(-1, 0);
	}
	else if (m_enemySprite.getPosition().x < randX)
	{
		m_enemySprite.move(1, 0);
	}

	if (m_enemySprite.getPosition().y > randY)
	{
		m_enemySprite.move(0, -1);
	}
	else if (m_enemySprite.getPosition().y < randY)
	{
		m_enemySprite.move(0, 1);
	}

}
