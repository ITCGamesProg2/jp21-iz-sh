#include "Bullet.h"

void Bullet::init()
{
	if (!m_bulletTexture.loadFromFile("./resources/bullet.png"))
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
	m_explosionParticles.draw(t_window);

	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletAlive[i])
		{
			t_window.draw(m_bulletSprite[i]);
		}
	}
}

void Bullet::input(sf::Vector2f t_shooterPos, sf::RenderWindow& t_window)
{
	//calculates the direction of the current bullet using mousePos and pos of player
	mousePos = (sf::Vector2f)sf::Mouse::getPosition(t_window);
	sf::Vector2f distanceVector = mousePos - t_shooterPos;

	m_shotDirection[m_bulletCount] = thor::unitVector(distanceVector);

	m_bulletAlive[m_bulletCount] = true;
	m_bulletSprite[m_bulletCount].setPosition(t_shooterPos);
	m_bulletCount++;

	if (m_bulletCount >= MAX_BULLET)
	{
		m_bulletCount = 0;
	}
}

void Bullet::update(Box& t_box,AI &t_enemy)
{
	boundaryCheck();

	m_explosionParticles.update();

	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletAlive[i])
		{
			m_bulletSprite[i].move(m_shotDirection[i].x * m_bulletSpeed,
				m_shotDirection[i].y * m_bulletSpeed);

			for (int j = 0; j < t_box.getMaxBox(); j++)
			{
				checkBoxIntersect(t_box.getSprite(j),t_box.getAlive(j));
			}
			checkIntersect(t_enemy);
		}
	}
}

void Bullet::boundaryCheck()
{
	//makes bullets disappear once they get off screen
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletSprite[i].getPosition().x > ScreenSize::s_width)
		{
			m_bulletAlive[i] = false;
		}
		else if (m_bulletSprite[i].getPosition().x < 0)
		{
			m_bulletAlive[i] = false;
		}
		else if (m_bulletSprite[i].getPosition().y > ScreenSize::s_height)
		{
			m_bulletAlive[i] = false;
		}
		else if (m_bulletSprite[i].getPosition().y < 0)
		{
			m_bulletAlive[i] = false;
		}
	}
}

void Bullet::checkBoxIntersect(sf::Sprite t_box, bool m_isAlive)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletSprite[i].getGlobalBounds().intersects(t_box.getGlobalBounds()))
		{
			if (m_bulletAlive[i] && m_isAlive)
			{
				m_explosionParticles.spawnExplosion(m_bulletSprite[i].getPosition(), sf::Color::Black);
				m_bulletAlive[i] = false;
			}
		}
	}
}

void Bullet::checkIntersect(AI& t_enemy)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletSprite[i].getGlobalBounds().intersects(t_enemy.getSprite().getGlobalBounds()))
		{
			if (m_bulletAlive[i] && t_enemy.isAlive())
			{

				m_explosionParticles.spawnExplosion(t_enemy.getSprite().getPosition(), sf::Color::Black);
				m_bulletAlive[i] = false;
				t_enemy.dealDamage();
			}
		}
	}
}

