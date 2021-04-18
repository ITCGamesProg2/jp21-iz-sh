#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Player.h"
#include "Box.h"
#include "ScreenSize.h"
#include <string>
#include "Bullet.h"
#include "HUD.h"
#include "Pickups.h"
#include "AI.h"
#include "AIBullet.h"
#include "Grid.h"
#include "MainMenu.h"

enum class
	GameState
{
	None,
	MainMenu,
	Help,
	Game
};

class Game
{
public:

	Game();

	void init();
	
	void processMouseInput(sf::Event t_event);

	void run();

	void draw();

	void update();

private:
	//create Window
	sf::RenderWindow m_window;
	sf::View m_view;

	Player m_player;
	sf::Font m_font;
	sf::Texture m_playerTextureSheet;
	sf::Sprite m_playerSpriteSheet;
	bool m_clickedMouse = false;

	Box m_box;
	Bullet m_bullet;
	AIBullet m_AIBullet;
	HUD m_HUD;
	Pickups m_pickups;
	AI m_enemy;
	Grid m_grid;
	MainMenu m_menu;
	GameState m_currentState = GameState::MainMenu;
};
