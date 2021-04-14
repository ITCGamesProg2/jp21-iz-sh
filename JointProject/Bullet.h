#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
class Bullet
{
public:
	Bullet() { ; }
	void init();
	void draw(sf::RenderWindow& t_window);
	void input(sf::Vector2f t_shooterPos, sf::RenderWindow t_window);
private:

	static const int MAX_BULLET = 20;
	int m_bulletDirection[MAX_BULLET];
	int m_bulletCount = 0;
	int m_bulletSpeed = 5;
	bool m_bulletAlive[MAX_BULLET];
	sf::Texture m_bulletTexture;
	sf::Sprite m_bulletSprite[MAX_BULLET];
	sf::Vector2f m_shotDirection{ 0,0 };
};


