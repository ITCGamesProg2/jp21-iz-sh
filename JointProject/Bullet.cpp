#include "Bullet.h"

void Bullet::init()
{
	if (!m_bulletTexture.loadFromFile("bullet.png"))
	{
		std::string s("Error loading bullet texture");
		throw std::exception(s.c_str());
	}
	for (int i = 0; i < MAX_BULLET; i++)
	{
		m_bulletSprite[i].setTexture(m_bulletTexture);
		m_bulletSprite[i].setOrigin(m_bulletSprite[i].getGlobalBounds().width / 2, m_bulletSprite[i].getGlobalBounds().height / 2);
		m_bulletSprite[i].setPosition(200, 200);
		m_bulletAlive[i] = false;
	}
}

void Bullet::draw(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletAlive[i])
		{
			t_window.draw(m_bulletSprite[i]);
		}
	}
}

void Bullet::input(sf::Vector2f t_shooterPos, sf::RenderWindow t_window)
{
	sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(t_window);
	sf::Vector2f distanceVector = mousePos - t_shooterPos;

	//m_shotDirection = vectorUnitVector(distanceVector) * m_bulletSpeed;
	m_bulletAlive[m_bulletCount] = true;
	m_bulletSprite[m_bulletCount].setPosition(t_shooterPos);
	m_bulletCount++;
	
	if (m_bulletCount >= MAX_BULLET)
	{
		m_bulletCount = 0;
	}
}

