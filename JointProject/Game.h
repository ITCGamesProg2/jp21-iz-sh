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
#include "Box.h"
#include <string>

const int NUM_BOXES = 5;

class Game
{
public:

	//create Window
	sf::RenderWindow window;
	sf::View view;

	

	Player player;
	sf::Texture playerTextureSheet;
	sf::Sprite playerSpriteSheet;

	Box boxes[NUM_BOXES];

	// index of active box, used currently to determine which box shows the E button prompt 
	int m_activeBox = 0;

	bool m_drawInteractPrompt = false;

	// text object of the E button Prompt
	std::string m_interactPrompt = "E";
	sf::Text m_interactPromptText;
	sf::Font m_font;

	Game();

	void init();
	
	void run();

	void draw();

	void update();

	void initText();

	/// <summary>
	/// get distance between 2 given entity vectors
	/// </summary>
	/// <param name="entity"></param>
	/// <param name="secondEntity"></param>
	/// <returns> float distanceBetween </returns>
	float distanceBetween(sf::Vector2f entity, sf::Vector2f secondEntity);
	
};
