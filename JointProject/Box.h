#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Box
{

public:

	void draw(sf::RenderWindow& win);

	/// <summary>
	/// will possibily be used for animations
	/// </summary>
	void update();

	/// <summary>
	/// give the box its inital sprite
	/// </summary>
	void initSprite();	

	/// <summary>
	/// set the position of the box
	/// </summary>
	/// <param name="position"></param>
	void setPosition(sf::Vector2f position);

	/// <summary>
	/// gets position of the box
	/// </summary>
	/// <returns> m_position </returns>
	sf::Vector2f getPosition();

	sf::Sprite getSprite() const
	{
		return m_boxSprite;
	}

private:

	sf::Vector2f m_position;
	sf::Sprite m_boxSprite;
	sf::Texture m_boxTexture;

};