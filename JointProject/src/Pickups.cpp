#include "Pickups.h"

void Pickups::draw(sf::RenderWindow& t_win)
{
	if (m_gunPickupAlive)
	{
		t_win.draw(m_gunSprite);
	}

	for (int i = 0; i < M_MAX_AMMO_PICKUPS; i++)
	{
		if (m_bulletPickUpAlive[i])
		{
			t_win.draw(m_ammoSprite[i]);
		}
		
	}
	
}

void Pickups::update(Player& t_player, int t_activeBox)
{
	if (t_player.isHidden() == true)
	{
		if (t_activeBox == m_usedGunBoxIndex)
		{
			if (m_gunPickupAlive)
			{
				t_player.giveGun();
				m_gunPickupAlive = false;
			}
			
		}

		for (int i = 0; i < M_MAX_AMMO_PICKUPS; i++)
		{
			if (m_bulletPickUpAlive[i])
			{
				if (t_activeBox == m_usedAmmoBoxIndex[i])
				{
					t_player.giveAmmo();
					m_bulletPickUpAlive[i] = false;
				}
			}

		}
	}

	//	WORK IN PROGRESS, PICKING UP BULLETS THAT ARE NOT IN BOXES

	/*else if (t_player.isHidden() == false)
	{
		if (m_gunPickupAlive)
		{
			if (t_player.getSprite().getGlobalBounds().intersects((m_gunSprite.getGlobalBounds())))
			{
				t_player.giveGun();
				m_gunPickupAlive = false;
			}
		}

		for (int i = 0; i < M_MAX_AMMO_PICKUPS; i++)
		{
			if (m_bulletPickUpAlive[i])
			{
				if (t_player.getSprite().getGlobalBounds().intersects((m_ammoSprite[i].getGlobalBounds())))
				{
					t_player.giveAmmo();
					m_bulletPickUpAlive[i] = false;
				}
			}
		}
	}*/
	
}

void Pickups::initPickups(Box& t_box)
{
	if (!m_ammoTexture.loadFromFile("./resources/bullet.png"))
	{
		std::string s("Error loading ammo pickup texture");
		throw std::exception(s.c_str());
	}
	for (int i = 0; i < M_MAX_AMMO_PICKUPS; i++)
	{
		m_ammoSprite[i].setTexture(m_ammoTexture);
		m_ammoSprite[i].setOrigin(m_ammoSprite[i].getGlobalBounds().width / 2, m_ammoSprite[i].getGlobalBounds().height / 2);
	}

	if (!m_gunSpriteTexture.loadFromFile("./resources/gun.png"))
	{
		std::string s("Error loading gun pickup texture");
		throw std::exception(s.c_str());
	}
	else
	{
		m_gunSprite.setTexture(m_gunSpriteTexture);
		m_gunSprite.setOrigin(m_gunSprite.getGlobalBounds().width / 2, m_gunSprite.getGlobalBounds().height / 2);
	}

	// generate which box will have the gun
	int boxContainingGun = rand() % t_box.getMaxBox();
	m_gunSprite.setPosition(t_box.getSprite(boxContainingGun).getPosition());

	// store which box contains the gun
	m_usedGunBoxIndex = boxContainingGun;

	// generate which boxes will have ammo pickups 
	for (int i = 0; i < M_MAX_AMMO_PICKUPS; i++)
	{
		// get a random box
		int boxContainingBullets = rand() % t_box.getMaxBox();

		// prevents repeat boxes being used
		for (int j = 0; j < M_MAX_AMMO_PICKUPS; j++)
		{
			while (boxContainingBullets == m_usedAmmoBoxIndex[j] || boxContainingBullets == m_usedGunBoxIndex)
			{
				boxContainingBullets = rand() % t_box.getMaxBox();
			}
		}

		// store the used box index so it doesnt get used again and which boxes contain ammo
		m_usedAmmoBoxIndex[i] = boxContainingBullets;
		
		// generate the ammo "in" the box
		m_ammoSprite[i].setPosition(t_box.getSprite(boxContainingBullets).getPosition());

	}
}
