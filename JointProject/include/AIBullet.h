#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "MathUtility.h"
#include "Box.h"
#include "Player.h"
#include "AI.h"
#include "Thor/Time.hpp"
#include "ParticalEffects.h"

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

	/// <summary>
	/// shoots a bullet from the AI towards the player
	/// </summary>
	/// <param name="t_playerPos"></param>
	/// <param name="t_aiPos"></param>
	void shootAtPlayer(sf::Vector2f t_playerPos, sf::Vector2f t_aiPos);

	/// <summary>
	/// moves bullets 
	/// </summary>
	void update(Box& t_box, AI& t_ai, Player& t_player, sf::Sound& t_boxShoot, sf::Sound& t_playerShot, sf::Sound& t_enemyAttack);
	/// <summary>
	/// disappears bullets when they hit box, also destroys box it hits
	/// </summary>
	/// <param name="t_box"></param>
	void checkBoxIntersect(Box& t_box, int t_arrayCell, sf::Sound& t_boxShoot);

	/// <summary>
	/// disappears bullets when they hit player, deals damage to player
	/// </summary>
	void checkPlayerIntersect(Player& t_player, sf::Sound& t_playerShot);

	/// <summary>
	/// disappears bullets once they leave screen
	/// </summary>
	void boundaryCheck();

	float distanceBetween(sf::Vector2f t_entity, sf::Vector2f t_secondEntity);

	void restart();

private:

	static const int MAX_BULLET = 15;
	int m_bulletDirection[MAX_BULLET];
	int m_bulletCount = 0; // determines which bullet is to be shot next
	int m_bulletSpeed = 5;
	bool m_bulletAlive[MAX_BULLET];
	sf::Texture m_bulletTexture;
	sf::Sprite m_bulletSprite[MAX_BULLET];
	sf::Vector2f m_shotDirection[MAX_BULLET];

	int m_damageToPlayer = 34;

	// bools controlling what shoot mode AI is in
	bool m_shootAtBoxMode = true;
	bool m_shootAtPlayerMode = false;

	// timer that controls the rate of fire of the AI
	thor::Timer m_firingTimer;
	static constexpr float BOX_FIRING_COOLDOWN = 5.0f;
	static constexpr float PLAYER_FIRING_COOLDOWN = 2.0f;


	ParticleSystem m_explosionParticles;

	/*thor::Timer m_backToPatrolDelay;
	static constexpr float DELAY = 3.0f;*/
};