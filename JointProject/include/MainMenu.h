#pragma once
#include <SFML\Graphics.hpp>
#include "ScreenSize.h"

class MainMenu
{

	//constant value for amount of buttons
	static const int m_buttonCount = 3;
	//reference for font used
	sf::Font m_font;
	//reference for texture used
	sf::Texture m_buttonTexture;
	sf::Texture m_pyreTexture;
	//array of the button texts
	sf::Text m_TextOnButton[m_buttonCount];
	//array of the button sprites
	sf::Sprite m_buttonPic[m_buttonCount];
	sf::Sprite m_pyreSprite;

	//offset off the left side
	float m_Offset{ 0.0f };
	//offset off the top 
	float m_OffsetOfTop{ 0.0f };
	//spacing between the buttons
	float m_buttonSpacing{ 0.0f };
	//height of buttons
	float m_buttonHeight{ 0.0f };
	//width of buttons
	float m_buttonWidth{ 0.0f };
	sf::RectangleShape m_menuScreen;

public:
	MainMenu();
	~MainMenu();

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window); //draws the sprites and texts
	int update(sf::Window& t_window); //checks if buttons pressed

};
