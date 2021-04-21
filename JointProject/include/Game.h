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
#include "GameOverScreen.h"
#include <SFML/Audio.hpp>


enum class
	GameState
{
	None,
	MainMenu,
	Help,
	Cutscene,
	Game,
	Win,
	Lose,
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

	void restart();

	/// <summary>
	/// loads the menu song and object sounds
	/// </summary>
	void initSound();

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

	bool m_enemyAlive;

	bool m_playerAlive;

	bool m_showGrid = false;

	Box m_box;
	Bullet m_bullet;
	AIBullet m_AIBullet;
	HUD m_HUD;
	Pickups m_pickups;
	AI m_enemy;
	MainMenu m_menu;
	HelpScreen m_help;
	Cutscene m_cut;
	Grid m_grid;
	GameOverScreen m_gameOverScreen;
	GameState m_currentState = GameState::MainMenu;

	sf::SoundBuffer m_menuBuffer;
	sf::Sound m_menuSong;
	sf::SoundBuffer m_warehouseBuffer;
	sf::Sound m_warehouse;
	sf::SoundBuffer m_boxOpenBuffer;
	sf::Sound m_boxOpen;
	sf::SoundBuffer m_boxShotBuffer;
	sf::Sound m_boxShot;
	sf::SoundBuffer m_playerShotBuffer;
	sf::Sound m_playerShot;
	sf::SoundBuffer m_enemyShotBuffer;
	sf::Sound m_enemyShot;
	sf::SoundBuffer m_playerAttackBuffer;
	sf::Sound m_playerAttack;
	sf::SoundBuffer m_enemyAttackBuffer;
	sf::Sound m_enemyAttack;
	sf::SoundBuffer m_itemGetBuffer;
	sf::Sound m_itemGet;

};
