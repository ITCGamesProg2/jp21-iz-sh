#include "Game.h"

Game::Game() : m_player(m_playerSpriteSheet)
{
	m_window.create(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height), "Joint Project");
}

void Game::init()
{
	m_view = m_window.getDefaultView();

	if (!m_playerTextureSheet.loadFromFile("./resources/character_robot_sheet.png"))
	{
		// error...
	}

	m_playerSpriteSheet.setTexture(m_playerTextureSheet);
	m_player.initAnimationData();
	m_player.startAnimaton(Player::PlayerAnimationState::walk);

	m_box.initBox();
	m_bullet.init();
	m_HUD.init();
	m_pickups.initPickups(m_box);

}

void Game::run()
{
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Clock clock;

	clock.restart();

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();

			if (event.type == sf::Event::MouseButtonReleased)
			{
				processMouseInput(event);
			}
		}

		timeSinceLastUpdate += clock.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{

			update();
			draw();

			timeSinceLastUpdate = sf::Time::Zero;
		}
	}
}

void Game::processMouseInput(sf::Event t_event)
{
	if (sf::Mouse::Left == t_event.key.code)
	{
		//player can only shoot if they are not in a box
		if (!m_player.isHidden())
		{
			m_bullet.input(m_player.getSprite().getPosition(), m_window);
		}
	}
}

void Game::draw()
{
	m_window.clear(sf::Color(53, 109, 146));

	m_box.draw(m_window);

	m_pickups.draw(m_window);

	// draw player if they are not hiding in a box
	if (m_player.isHidden() == false)
	{
		m_player.draw(m_window);
	}
	m_bullet.draw(m_window);

	m_HUD.draw(m_window);

	m_window.display();
}

void Game::update()
{
	// update player movement
	m_player.update();
	m_box.update(m_player);
	m_bullet.update(m_box);
	m_HUD.update(m_player);
	
}
