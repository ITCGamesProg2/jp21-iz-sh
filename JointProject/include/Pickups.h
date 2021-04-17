#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Box.h"

class Pickups
{
public:

	Pickups()
	{
		m_gunPickupAlive = true;
		for (int i = 0; i < M_MAX_AMMO_PICKUPS; i++)
		{
			m_bulletPickUpAlive[i] = true;
		}
	}

	void draw(sf::RenderWindow& t_win);

	void update(Player& t_player, int t_activeBox);

	void initPickups(Box& t_box);

private:
	static const int M_MAX_AMMO_PICKUPS = 3;
	sf::Vector2f m_position;
	sf::Sprite m_ammoSprite[M_MAX_AMMO_PICKUPS];
	sf::Texture m_ammoTexture;

	sf::Sprite m_gunSprite;
	sf::Texture m_gunSpriteTexture;

	int m_usedAmmoBoxIndex[M_MAX_AMMO_PICKUPS];
	int m_usedGunBoxIndex;

	// check if the ammo pickup can be picked up
	bool m_bulletPickUpAlive[M_MAX_AMMO_PICKUPS];

	// check if the gun pickup can be picked up
	bool m_gunPickupAlive;
};