// platform game
// Author :Noel O' Hara
// Extra Code: Izabela Zelek 
// Robot Animation: Stephen Hurley
// Coins Animations: Rauls Bergs
//Link: https://instituteoftechnol663-my.sharepoint.com/:v:/g/personal/c00247865_itcarlow_ie/ETTFY8tC4AhBvVlpaJAAtgEBsAP_AF4om9dFaxYXrbspDg?e=wI9KHc
#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Player.h"
#include <string>

class Game
{
public:
	//create Window
	sf::RenderWindow window;
	sf::View view;
	float randomNum;
	float timeChange = 0;

	//sf::RectangleShape playerShape;
	int pixelsPerMeter = 80;

	sf::Vector2f velocity{ 0,0 };
	sf::Vector2f gravity{ 0,12 };
	sf::Vector2f jumpPushOff{ 0,6 * pixelsPerMeter };

	bool gameOver = false;

	Player player;
	sf::Texture playerTextureSheet;
	sf::Sprite playerSpriteSheet;


	Game();



	void init();
	
	void run();
	
};
