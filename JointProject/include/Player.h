#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "ScreenSize.h"

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
	void update(sf::Vector2f t_mousePos, bool& t_clickedMouse);


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

	bool canE()
	{
		return m_canPressE;
	}

	void giveAmmo()
	{
		m_ammo += 5;
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

};