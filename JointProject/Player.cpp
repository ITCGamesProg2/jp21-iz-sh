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

	spriteSheet.setOrigin(spriteSheet.getGlobalBounds().width / 2, spriteSheet.getGlobalBounds().height / 2);

	win.draw(spriteSheet);
}

void Player::Update()
{
	if (m_hidden == false)
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

}

void Player::interactWithBox()
{
	// check if E press delay is finished
	if (m_canPressE)
	{
		// check if player pressed E
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			// m_hidden bool flip flop
			if (m_hidden)
			{
				m_hidden = false;
			}
			else
			{
				m_hidden = true;

			}

			// disable ability to press E
			m_canPressE = false;
			// reset E input delay counter
			m_EInputDelayCounter = m_EInputDelay;
		}
	}
	else // if there currently is a delay
	{
		m_EInputDelayCounter--;

		if (m_EInputDelayCounter <= 0)
		{
			m_canPressE = true;
		}
	}
}

void Player::boundaryCheck()
{
	if (spriteSheet.getPosition().x > 800)
	{
		spriteSheet.setPosition(800, spriteSheet.getPosition().y);
	}
	else if (spriteSheet.getPosition().x < 0)
	{
		spriteSheet.setPosition(0, spriteSheet.getPosition().y);
	}
	if (spriteSheet.getPosition().y > 600)
	{
		spriteSheet.setPosition(spriteSheet.getPosition().x, 600);
	}
	else if (spriteSheet.getPosition().y < 0)
	{
		spriteSheet.setPosition(spriteSheet.getPosition().x,0);
	}
}
