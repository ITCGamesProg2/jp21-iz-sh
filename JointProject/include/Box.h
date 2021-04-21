#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"



class Box
{

public:

	Box() 
	{ 
		for (int i = 0; i < M_MAX_BOX; i++)
		{
			m_boxAlive[i] = true;
		}
	}
	void draw(sf::RenderWindow& t_win);

	/// <summary>
	/// will possibily be used for animations
	/// </summary>
	void update(Player &t_player);

	/// <summary>
	/// give the box its inital sprite, and the text
	/// </summary>
	void init(sf::Font& t_font);


	/// <summary>
	/// get distance between 2 given entity vectors
	/// </summary>
	/// <param name="entity"></param>
	/// <param name="secondEntity"></param>
	/// <returns> float distanceBetween </returns>
	float distanceBetween(sf::Vector2f t_entity, sf::Vector2f t_secondEntity);

/// <summary>
/// check for collisions between player and boxes
/// </summary>
/// <param name="boxSprite"></param>
	void collisionBetweenPlayerAndBox(Player& t_playerSprite);

	sf::Sprite getSprite(int t_arrayCell)
	{
		return m_boxSprite[t_arrayCell];
	}

	int getMaxBox()
	{
		return M_MAX_BOX;
	}

	int getActiveBox()
	{
		return m_activeBox;
	}

	void setAlive(int t_arrayCell)
	{
		m_boxAlive[t_arrayCell] = false;
	}

	bool getAlive(int t_arrayCell)
	{
		return m_boxAlive[t_arrayCell];
	}

	int getNumberOfBoxesInGame()
	{
		return m_currentNumBoxesInGame;
	}

	void reduceNumOfBoxes()
	{
		m_currentNumBoxesInGame -= 1;
	}

	void restart();

private:

	static const int M_MAX_BOX = 18;
	sf::Sprite m_boxSprite[M_MAX_BOX];
	sf::Texture m_boxTexture;
	sf::Vector2f m_previousPosition;

	// index of active box
	int m_activeBox = 0;

	int m_currentNumBoxesInGame = M_MAX_BOX;

	bool m_drawInteractPrompt = false;

	// text object of the E button Prompt
	std::string m_interactPrompt = "E";
	sf::Text m_interactPromptText;

	bool m_boxAlive[M_MAX_BOX];

};