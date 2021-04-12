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

	Player(sf::Sprite& spheet);

	void InitAnimationData();
	
	void startAnimaton(PlayerAnimationState _animationState);

	void Draw(sf::RenderWindow& win);

	/// <summary>
	/// gets player input and moves the character
	/// </summary>
	void Update();

	/// <summary>
	/// Stops the player from leaving the screen
	/// </summary>
	void boundaryCheck();
};