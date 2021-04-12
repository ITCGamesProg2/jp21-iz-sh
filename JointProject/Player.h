#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:

	enum  class PlayerAnimationState { walk, idle };

	PlayerAnimationState animationState = PlayerAnimationState::walk;
	Animation animations[4];
	AnimationSheet animSheet;
	sf::Vector2f position;
	sf::Sprite& spriteSheet;

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
	int m_EInputDelay = 30;
	int m_EInputDelayCounter = m_EInputDelay;

	Player(sf::Sprite& spheet);

	void InitAnimationData();
	
	void startAnimaton(PlayerAnimationState _animationState);

	void Draw(sf::RenderWindow& win);

	/// <summary>
	/// gets player input and moves the character
	/// </summary>
	void Update();

	/// <summary>
	/// checks if player inputs to hide in or get out of a box
	/// </summary>
	void interactWithBox();

	/// <summary>
	/// Stops the player from leaving the screen
	/// </summary>
	void boundaryCheck();
};