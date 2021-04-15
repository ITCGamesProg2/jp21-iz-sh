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
	sf::Texture m_playerTextureSheet;
	sf::Sprite m_playerSpriteSheet;
	bool m_clickedMouse = false;

	Box m_box;
	Bullet m_bullet;
	HUD m_HUD;

	Pickups m_pickups;

	
};
