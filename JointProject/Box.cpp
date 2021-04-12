#include "Box.h"

void Box::draw(sf::RenderWindow& win)
{
	win.draw(m_boxSprite);
}

void Box::update()
{

}

void Box::initSprite()
{
	if (!m_boxTexture.loadFromFile("closedBox.png"))
	{
		std::string s("Error loading spritesheet");
		throw std::exception(s.c_str());
	}

	m_boxSprite.setTexture(m_boxTexture);
	m_boxSprite.setScale(0.1, 0.1);
	m_boxSprite.setOrigin(m_boxSprite.getGlobalBounds().width / 2, m_boxSprite.getGlobalBounds().height / 2);
}

void Box::setPosition(sf::Vector2f position)
{
	m_position = position;
	m_boxSprite.setPosition(m_position);
}

sf::Vector2f Box::getPosition()
{
	return m_position;
}
