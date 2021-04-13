#include "Player.h"

Player::Player(sf::Sprite& t_spheet) : m_playerSprite(t_spheet)
{
}

void Player::initAnimationData()
{

	m_animations[int(PlayerAnimationState::walk)] = { 8, 36,5,true };
	m_animations[int(PlayerAnimationState::idle)] = { 3,21,80,true };
	m_animationState = PlayerAnimationState::walk;

	m_animSheet.init(m_playerSprite.getGlobalBounds().width, m_playerSprite.getGlobalBounds().height, 5, 9);
}

void Player::startAnimaton(PlayerAnimationState t_animationState)
{
	m_animationState = t_animationState;
	m_animSheet.startAnimation(m_animations[int(m_animationState)]);
}

void Player::draw(sf::RenderWindow& t_win)
{
	m_animSheet.nextFrame();
	m_playerSprite.setTextureRect(m_animSheet.getFrame());

	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width / 2, (m_playerSprite.getGlobalBounds().height / 2) + 15);

	t_win.draw(m_playerSprite);
}

void Player::update()
{
	if (m_hidden == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_animationState = PlayerAnimationState::walk;

			m_playerSprite.move(0, -2);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_animationState = PlayerAnimationState::walk;

			m_playerSprite.move(0, 2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_animationState = PlayerAnimationState::walk;

			m_playerSprite.move(-2, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_animationState = PlayerAnimationState::walk;

			m_playerSprite.move(2, 0);
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
	if (m_playerSprite.getPosition().x > ScreenSize::s_width - m_playerSprite.getGlobalBounds().width / 2)
	{
		m_playerSprite.setPosition(ScreenSize::s_width - m_playerSprite.getGlobalBounds().width / 2, m_playerSprite.getPosition().y);
	}
	else if (m_playerSprite.getPosition().x < m_playerSprite.getGlobalBounds().width / 2)
	{
		m_playerSprite.setPosition(m_playerSprite.getGlobalBounds().width / 2, m_playerSprite.getPosition().y);
	}
	if (m_playerSprite.getPosition().y > ScreenSize::s_height - m_playerSprite.getGlobalBounds().width / 2)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, ScreenSize::s_height - m_playerSprite.getGlobalBounds().width / 2);
	}
	else if (m_playerSprite.getPosition().y < m_playerSprite.getGlobalBounds().height / 2)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x,m_playerSprite.getGlobalBounds().height / 2);
	}
}
