#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "MathUtility.h"
#include "Box.h"
#include "Player.h"
#include "AI.h"

class AIBullet
{
public:
	AIBullet() { ; }
	void init();
	void draw(sf::RenderWindow& t_window);
	/// <summary>
	/// shoots a bullet from the AI towards the cloest box
	/// </summary>
	/// <param name="t_boxPos"></param>
	/// <param name="t_aiPos"></param>
	void shootAtBox(sf::Vector2f t_boxPos, sf::Vector2f t_aiPos);

	void shootAtPlayer(sf::Vector2f t_playerPos, sf::Vector2f t_aiPos);

	/// <summary>
	/// moves bullets 
	/// </summary>
	void update(Box& t_box, AI& t_ai, Player& t_player);
	/// <summary>
	/// disappears bullets when they hit box, also destroys box it hits
	/// </summary>
	/// <param name="t_box"></param>
	void checkBoxIntersect(Box& t_box, int t_arrayCell);

	/// <summary>
	/// disappears bullets when they hit player, deals damage
	/// </summary>
	void checkPlayerIntersect(Player& t_player);

	float distanceBetween(sf::Vector2f t_entity, sf::Vector2f t_secondEntity);

private:

	static const int MAX_BULLET = 1;
	int m_bulletDirection[MAX_BULLET];
	int m_bulletCount = 0; // determines which bullet is to be shot next
	int m_bulletSpeed = 5;
	bool m_bulletAlive[MAX_BULLET];
	sf::Texture m_bulletTexture;
	sf::Sprite m_bulletSprite[MAX_BULLET];
	sf::Vector2f m_shotDirection[MAX_BULLET];

	int m_damageToPlayer = 100;

	bool m_shootAtBox = true;
	bool m_shootAtPlayer = false;
};