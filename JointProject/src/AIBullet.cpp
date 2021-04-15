#include "AIBullet.h"

void AIBullet::init()
{
	if (!m_bulletTexture.loadFromFile("./resources/bullet.png"))
	{
		std::string s("Error loading AIbullet texture");
		throw std::exception(s.c_str());
	}
	for (int i = 0; i < MAX_BULLET; i++)
	{
		m_bulletSprite[i].setTexture(m_bulletTexture);
		m_bulletSprite[i].setOrigin(m_bulletSprite[i].getGlobalBounds().width / 2, m_bulletSprite[i].getGlobalBounds().height / 2);
		m_bulletSprite[i].setPosition(0, 0);
		m_bulletAlive[i] = false;
	}
}

void AIBullet::draw(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletAlive[i])
		{
			t_window.draw(m_bulletSprite[i]);
		}
	}
}

void AIBullet::shootAtBox(sf::Vector2f t_boxPos, sf::Vector2f t_aiPos)
{
	//calculates the direction of the current bullet using cloesest box pos and aiPos
	sf::Vector2f distanceVector = t_boxPos - t_aiPos;

	m_shotDirection[m_bulletCount] = thor::unitVector(distanceVector);

	m_bulletAlive[m_bulletCount] = true;
	m_bulletSprite[m_bulletCount].setPosition(t_aiPos);
	m_bulletCount++;

	if (m_bulletCount >= MAX_BULLET)
	{
		m_bulletCount = 0;
	}
}

void AIBullet::shootAtPlayer(sf::Vector2f t_playerPos, sf::Vector2f t_aiPos)
{
	//calculates the direction of the current bullet using cloesest box pos and aiPos
	sf::Vector2f distanceVector = t_playerPos - t_aiPos;

	m_shotDirection[m_bulletCount] = thor::unitVector(distanceVector);

	m_bulletAlive[m_bulletCount] = true;
	m_bulletSprite[m_bulletCount].setPosition(t_aiPos);
	m_bulletCount++;

	if (m_bulletCount >= MAX_BULLET)
	{
		m_bulletCount = 0;
	}
}

void AIBullet::update(Box& t_box, AI& t_ai, Player& t_player)
{
	// VERY IMPORTANT NOTE TO SELF (STEPHEN): MODIFY LATER TO HAVE TIMER CONTROLLING AI FIRE RATE. RIGHT NOW CAN ONLY SHOOT ONE BULLET PER GAME
	// ALSO INTRODUCE SHOOTING STATES: SHOOTATBOX WHEN PLAYER IS UNDETECTED, SHOOTATPLAYER WHEN PLAYER IS BEING CHASED
	
	// check if AI should shoot at box

	// V.I CONT: POSSIBLE THAT AI WILL SHOOT AT DESTROYED BOX IF IT WAS THE CLOESEST ONE, MODIFY WHEN MULTIPLE BULLETS CAN BE FIRED
	if (m_shootAtBox)
	{
		int closestBoxIndex = 0;
		float closestBoxDistance = 9999;

		// find the closest box to the AI
		for (int i = 0; i < t_box.getMaxBox(); i++)
		{
			float currentdistanceBetween = distanceBetween(t_box.getSprite(i).getPosition(), t_ai.getSprite().getPosition());

			if (currentdistanceBetween < closestBoxDistance)
			{
				closestBoxIndex = i;
				closestBoxDistance = currentdistanceBetween;
			}
		}

		// shoot at that box
		shootAtBox(t_box.getSprite(closestBoxIndex).getPosition(), t_ai.getSprite().getPosition());
		m_shootAtBox = false;
	}
	else if (m_shootAtPlayer) // shoot at player instead
	{
		shootAtPlayer(t_player.getSprite().getPosition(), t_ai.getSprite().getPosition());
		m_shootAtPlayer = false;
	}
	
	for (int i = 0; i < MAX_BULLET; i++)
	{
		boundaryCheck();

		if (m_bulletAlive[i])
		{
			m_bulletSprite[i].move(m_shotDirection[i].x * m_bulletSpeed,
				m_shotDirection[i].y * m_bulletSpeed);

			for (int j = 0; j < t_box.getMaxBox(); j++)
			{
				checkBoxIntersect(t_box, j);
			}

			checkPlayerIntersect(t_player);
		}
	}
}

void AIBullet::checkBoxIntersect(Box &t_box, int t_arrayCell)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletSprite[i].getGlobalBounds().intersects(t_box.getSprite(t_arrayCell).getGlobalBounds()))
		{
			if (m_bulletAlive[i] && t_box.getAlive(t_arrayCell))
			{
				t_box.setAlive(t_arrayCell);
				m_bulletAlive[i] = false;
			}
		}
	}
}

void AIBullet::checkPlayerIntersect(Player& t_player)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (m_bulletSprite[i].getGlobalBounds().intersects(t_player.getSprite().getGlobalBounds()))
		{
			if (m_bulletAlive[i] && t_player.isAlive())
			{
				m_bulletAlive[i] = false;
				t_player.takeDamage(m_damageToPlayer);
			}
		}
	}
}

void AIBullet::boundaryCheck()
{
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

float AIBullet::distanceBetween(sf::Vector2f t_entity, sf::Vector2f t_secondEntity)
{
	float distanceBetween = ((t_secondEntity.x - t_entity.x) * (t_secondEntity.x - t_entity.x)) + ((t_secondEntity.y - t_entity.y) * (t_secondEntity.y - t_entity.y));
	distanceBetween = std::sqrt(distanceBetween);
	return distanceBetween;
}
