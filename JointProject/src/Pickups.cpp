#include "Pickups.h"

Pickups::Pickups()
{
}

void Pickups::draw(sf::RenderWindow& t_win)
{
	t_win.draw(m_gunSprite);

	for (int i = 0; i < M_MAX_AMMO_PICKUPS; i++)
	{
		t_win.draw(m_ammoSprite[i]);
	}
	
}

void Pickups::update(Player& t_player)
{
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

	// generate which boxes will have ammo pickups 
	for (int i = 0; i < M_MAX_AMMO_PICKUPS; i++)
	{
		// get a random box
		int boxContainingBullets = rand() % t_box.getMaxBox();

		// prevents repeat boxes being used
		for (int j = 0; j < M_MAX_AMMO_PICKUPS; j++)
		{
			while (boxContainingBullets == m_usedBoxIndex[j] || boxContainingBullets == boxContainingGun)
			{
				boxContainingBullets = rand() % t_box.getMaxBox();
			}
		}

		// store the used box index so it doesnt get used again
		m_usedBoxIndex[i] = boxContainingBullets;
		
		// generate the ammo "in" the box
		m_ammoSprite[i].setPosition(t_box.getSprite(boxContainingBullets).getPosition());
	}
}
