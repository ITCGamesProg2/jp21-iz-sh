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
#include "MainMenu.h"
#include "Help.h"
#include "Cutscene.h"

enum class
	GameState
{
	None,
	MainMenu,
	Help,
	Cutscene,
	Game,
	Win,
	Loose,
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
	sf::Texture m_bgTexture;
	sf::Sprite m_bgSpriteSheet;
	bool m_clickedMouse = false;

	static const int M_NUM_ENEMIES = 2;

	Box m_box;
	Bullet m_bullet;
	AIBullet m_AIBullet[M_NUM_ENEMIES];
	HUD m_HUD;
	Pickups m_pickups;
	AI m_enemy[M_NUM_ENEMIES];
	MainMenu m_menu;
	HelpScreen m_help;
	Cutscene m_cut;
	Grid m_grid;
	GameState m_currentState = GameState::Game;
};
