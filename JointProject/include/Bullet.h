#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "MathUtility.h"
#include "Box.h"

class Bullet
{
public:
	Bullet() { ; }
	void init();
	void draw(sf::RenderWindow& t_window);
	/// <summary>
	/// calculates where the bullets head towards
	/// </summary>
	/// <param name="t_shooterPos"></param>
	/// <param name="t_window"></param>
	void input(sf::Vector2f t_shooterPos, sf::RenderWindow& t_window);
	/// <summary>
	/// moves bullets towards mouse click
	/// </summary>
	void update(Box& box);
	/// <summary>
	/// disappears bullets once they leave screen
	/// </summary>
	void boundaryCheck();
	/// <summary>
	/// disappears bullets when they hit box
	/// </summary>
	/// <param name="t_box"></param>
	void checkBoxIntersect(sf::Sprite t_box);

	sf::Vector2f getMousePos()
	{
		return mousePos;
	}

private:

	static const int MAX_BULLET = 20;
	int m_bulletDirection[MAX_BULLET];
	int m_bulletCount = 0; // determines which bullet is to be shot next
	int m_bulletSpeed = 5;
	bool m_bulletAlive[MAX_BULLET];
	sf::Texture m_bulletTexture;
	sf::Sprite m_bulletSprite[MAX_BULLET];
	sf::Vector2f m_shotDirection[MAX_BULLET];
	sf::Vector2f mousePos;
};


