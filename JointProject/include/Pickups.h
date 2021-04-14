#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Box.h"

class Pickups
{
public:

	Pickups();

	void draw(sf::RenderWindow& t_win);

	void update(Player& t_player);

	void initPickups(Box &t_box);

private:
	static const int M_MAX_AMMO_PICKUPS = 3;
	sf::Vector2f m_position;
	sf::Sprite m_ammoSprite[M_MAX_AMMO_PICKUPS];
	sf::Texture m_ammoTexture;

	sf::Sprite m_gunSprite;
	sf::Texture m_gunSpriteTexture;

	int m_usedBoxIndex[M_MAX_AMMO_PICKUPS];

};