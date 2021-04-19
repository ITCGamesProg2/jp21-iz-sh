#pragma once
#include <SFML\Graphics.hpp>
#include "ScreenSize.h"
#include "Player.h"

class MainMenu
{

	//constant value for amount of buttons
	static const int MAX_BUTTON = 3;
	static const int MAX_COLOUR = 8;
	//reference for font used
	sf::Font m_font;
	//reference for texture used
	sf::Texture m_buttonTexture;
	sf::Texture m_robotTexture;
	sf::Texture m_menuTexture;
	//array of the button texts
	sf::Text m_TextOnButton[MAX_BUTTON];
	//array of the button sprites
	sf::Sprite m_buttonSprite[MAX_BUTTON];
	sf::Sprite m_robotSprite;
	sf::Sprite m_menuScreen;

	sf::Vector2f m_originalPos[MAX_BUTTON];
	sf::Vector2f m_pushedDownPos[MAX_BUTTON];
	sf::String m_menuTexts[MAX_BUTTON] = { "Play","Help","Exit" };
	sf::Vector2f m_buttonOffset{ 200,200 };
	sf::RectangleShape m_colourSwatch[MAX_COLOUR];
	sf::RectangleShape m_colourBg;
	sf::Color m_robotColour[MAX_COLOUR] = {{227, 58, 58},{218, 107, 8 },{238, 210, 95 },{84, 199, 81 }, {36, 153, 194 },{146, 61, 209 },{226, 63, 178 }, {sf::Color::White} };

	//spacing between the buttons
	float m_buttonSpacing{ 250.0f };
	
public:
	MainMenu();
	~MainMenu();

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window); //draws the sprites and texts
	int processInput(sf::Window& t_window, Player& t_player, sf::Event t_event); //checks if buttons pressed
	void update(sf::Window& t_window);

};
