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

	if (!m_font.loadFromFile("./resources/arial.ttf"))
	{
		std::string s("Error loading font");
		throw std::exception(s.c_str());
	}

	m_playerSpriteSheet.setTexture(m_playerTextureSheet);
	m_player.initAnimationData();
	m_player.startAnimaton(Player::PlayerAnimationState::walk);

	m_enemy.init();
	m_box.init(m_font);
	m_bullet.init();
	m_AIBullet.init();
	m_HUD.init(m_font);
	m_pickups.initPickups(m_box);
	m_grid.makeGrid();
	m_grid.markImpassableCells(m_box);
	m_menu.initialise(m_font);

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
			{
				m_window.close();
			}

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
	switch (m_currentState)
	{
	case GameState::None:
		break;
	case GameState::MainMenu:
		break;
	case GameState::Help:
		break;
	case GameState::Game:
		if (sf::Mouse::Left == t_event.key.code)
		{
			//player can only shoot if they are not in a box
			if (!m_player.isHidden() && m_player.doesHaveGun() && m_player.getAmmo() > 0)
			{
				m_player.giveAmmo(-1);
				m_clickedMouse = true;
				m_bullet.input(m_player.getSprite().getPosition(), m_window);
			}
		}
		break;
	default:
		break;
	}
}

void Game::draw()
{
	m_window.clear(sf::Color(53, 109, 146));

	switch (m_currentState)
	{
	case GameState::None:
		break;
	case GameState::MainMenu:
		m_menu.render(m_window);
		break;
	case GameState::Help:
		break;
	case GameState::Game:
		m_enemy.draw(m_window);
		m_AIBullet.draw(m_window);
		m_box.draw(m_window);
		m_pickups.draw(m_window);
		m_player.draw(m_window);
		m_bullet.draw(m_window);
		m_HUD.draw(m_window);
		break;
	default:
		break;
	}
	m_window.display();
}

void Game::update()
{
	int state = 0;
	switch (m_currentState)
	{
	case GameState::None:
		break;
	case GameState::MainMenu:
		state = m_menu.update(m_window);
		if (state == 1)
		{
			m_currentState = GameState::Game;
		}
		else if (state == 2)
		{
			m_currentState = GameState::Help;
		}
		break;
	case GameState::Help:
		break;
	case GameState::Game:
		// update player movement
		m_player.update(m_bullet.getMousePos(), m_clickedMouse);
		m_enemy.update();
		m_box.update(m_player);
		m_bullet.update(m_box, m_enemy);
		m_AIBullet.update(m_box, m_enemy, m_player);
		m_HUD.update(m_player);
		m_grid.update();

		m_pickups.update(m_player, m_box.getActiveBox());
		break;
	default:
		break;
	}
	
	
}
