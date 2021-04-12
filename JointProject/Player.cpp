#include "Player.h"

Player::Player(sf::Sprite& spheet) : spriteSheet(spheet)
{
}

void Player::InitAnimationData()
{

	animations[int(PlayerAnimationState::walk)] = { 8, 36,5,true };
	animations[int(PlayerAnimationState::idle)] = { 3,21,80,true };
	animationState = PlayerAnimationState::walk;

	animSheet.Init(spriteSheet.getGlobalBounds().width, spriteSheet.getGlobalBounds().height, 5, 9);
}

void Player::startAnimaton(PlayerAnimationState _animationState)
{
	animationState = _animationState;
	animSheet.StartAnimation(animations[int(animationState)]);
}

void Player::Draw(sf::RenderWindow& win)
{
	animSheet.nextFrame();
	spriteSheet.setTextureRect(animSheet.GetFrame());
	win.draw(spriteSheet);
}

void Player::Update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		animationState = PlayerAnimationState::walk;

		spriteSheet.move(0, -2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		animationState = PlayerAnimationState::walk;

		spriteSheet.move(0, 2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		animationState = PlayerAnimationState::walk;

		spriteSheet.move(-2, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		animationState = PlayerAnimationState::walk;

		spriteSheet.move(2, 0);
	}
	boundaryCheck();
}

void Player::boundaryCheck()
{
	if (spriteSheet.getPosition().x > 700)
	{
		spriteSheet.setPosition(700, spriteSheet.getPosition().y);
	}
	else if (spriteSheet.getPosition().x < 0)
	{
		spriteSheet.setPosition(0, spriteSheet.getPosition().y);
	}
	if (spriteSheet.getPosition().y > 450)
	{
		spriteSheet.setPosition(spriteSheet.getPosition().x,450);
	}
	else if (spriteSheet.getPosition().y < 0)
	{
		spriteSheet.setPosition(spriteSheet.getPosition().x,0);
	}
}
