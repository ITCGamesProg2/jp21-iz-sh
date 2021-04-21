#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "ScreenSize.h"
#include <iostream>

class Player
{
public:
	enum  class PlayerAnimationState { walk, idle };
	
	Player(sf::Sprite& t_spheet);

	void initAnimationData();
	
	void startAnimaton(PlayerAnimationState t_animationState);

	void draw(sf::RenderWindow& t_win);

	/// <summary>
	/// gets player input and moves the character
	/// </summary>
	/// <param name="t_mousePos"></param>
	/// <param name="t_clickedMouse"></param>
	/// <returns>bool determining if player is still alive in order to change gamestates</returns>
	bool update(sf::Vector2f t_mousePos, bool& t_clickedMouse);


	/// <summary>
	/// checks if player inputs to hide in or get out of a box
	/// </summary>
	void interactWithBox();

	/// <summary>
	/// Stops the player from leaving the screen
	/// </summary>
	void boundaryCheck();


	void setPos(sf::Vector2f t_previous)
	{
		m_playerSprite.setPosition(t_previous);
	}

	sf::Sprite getSprite()
	{
		return m_playerSprite;
	}

	bool isHidden()
	{
		return m_hidden;
	}

	void setHiddenStatus(bool t_hiddenStatus)
	{
		m_hidden = t_hiddenStatus;
	}

	bool canE()
	{
		return m_canPressE;
	}

	void giveAmmo(int t_value)
	{
		m_ammo += t_value;
	}

	void giveGun()
	{
		m_hasGun = true;
	}

	int getAmmo()
	{
		return m_ammo;
	}

	bool doesHaveGun()
	{
		return m_hasGun;
	}

	void takeDamage(int damage)
	{
		m_health -= damage;
	}

	bool isAlive()
	{
		return m_alive;
	}

	/// <summary>
	/// sets the colour of player to the chosen one in menu
	/// </summary>
	/// <param name="t_color"></param>
	void setColour(sf::Color& t_color)
	{
		m_playerSprite.setColor(t_color);
	}

	void restart();

private:

	PlayerAnimationState m_animationState = PlayerAnimationState::walk;
	Animation m_animations[4];
	AnimationSheet m_animSheet;
	sf::Vector2f m_position;
	sf::Sprite& m_playerSprite;

	/// <summary>
	/// bool determining if player is hidden in a box or not
	/// </summary>
	bool m_hidden = false;

	/// <summary>
	/// bool determining if player can press E to interact with a box when near it
	/// </summary>
	bool m_canPressE = true;

	/// <summary>
	/// The delay on E button presses and a countdown until E can be pressed or processed again
	/// </summary>
	int m_EInputDelay = 50;
	int m_EInputDelayCounter = m_EInputDelay;

	int m_ammo = 0;

	bool m_hasGun = false;

	int m_health = 100;

	bool m_alive = true;


};