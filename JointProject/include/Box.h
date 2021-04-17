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
			m_alive[i] = true;
		}
	}
	void draw(sf::RenderWindow& t_win);

	/// <summary>
	/// will possibily be used for animations
	/// </summary>
	void update(Player &t_player);

	/// <summary>
	/// give the box its inital sprite
	/// </summary>
	void initBox();	

	/// <summary>
	/// gets position of the box
	/// </summary>
	/// <returns> m_position </returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// loads in text attributes
	/// </summary>
	void initText();

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
		m_alive[t_arrayCell] = false;
	}

	bool getAlive(int t_arrayCell)
	{
		return m_alive[t_arrayCell];
	}

private:

	static const int M_MAX_BOX = 6;
	sf::Sprite m_boxSprite[M_MAX_BOX];
	sf::Texture m_boxTexture;
	sf::Vector2f m_previousPosition;

	// index of active box
	int m_activeBox = 0;

	bool m_drawInteractPrompt = false;

	// text object of the E button Prompt
	std::string m_interactPrompt = "E";
	sf::Text m_interactPromptText;
	sf::Font m_font;

	bool m_alive[M_MAX_BOX];

};