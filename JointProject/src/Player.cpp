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
	m_playerSprite.setTextureRect(m_animSheet.getFrame());
	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width / 2, (m_playerSprite.getGlobalBounds().height / 2) + 15);
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

	if (m_hidden == false && m_alive)
	{
		t_win.draw(m_playerSprite);
	}
	
}

void Player::update(sf::Vector2f t_mousePos, bool& t_clickedMouse)
{
	if (m_health <= 0)
	{
		m_alive = false;
	}

	std::cout << m_health << std::endl;

	if (m_alive)
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
				m_playerSprite.setScale(-1, 1);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				m_animationState = PlayerAnimationState::walk;

				m_playerSprite.move(2, 0);
				m_playerSprite.setScale(1, 1);

			}

			boundaryCheck();
		}
		if (t_mousePos.x < m_playerSprite.getPosition().x && t_clickedMouse)
		{
			m_playerSprite.setScale(-1, 1);
			t_clickedMouse = false;
		}
		else if (t_mousePos.x > m_playerSprite.getPosition().x&& t_clickedMouse)
		{
			m_playerSprite.setScale(1, 1);
			t_clickedMouse = false;
		}
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
