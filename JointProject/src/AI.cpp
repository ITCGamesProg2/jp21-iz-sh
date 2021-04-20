#include "AI.h"

void AI::init(Grid& t_grid)
{
	if (!m_enemyTexture.loadFromFile("./resources/robot.png"))
	{
		std::string s("Error loading enemy sprite");
		throw std::exception(s.c_str());
	}
	m_enemySprite.setTexture(m_enemyTexture);
	m_enemySprite.setOrigin(m_enemySprite.getGlobalBounds().width / 2, m_enemySprite.getGlobalBounds().height / 2);
	// positions to test where the AI will shoot its bullet
	
	randX = std::rand() % (ScreenSize::s_width - 200) + 100;
	randY = std::rand() % (ScreenSize::s_height - 200) + 100;

	m_rangeCircle.setRadius(m_spotPlayerRange);
	m_rangeCircle.setPosition(m_enemySprite.getPosition());
	m_rangeCircle.setOrigin(m_rangeCircle.getGlobalBounds().width / 2, m_rangeCircle.getGlobalBounds().height / 2);
	m_rangeCircle.setFillColor(sf::Color::Transparent);
	m_rangeCircle.setOutlineThickness(2u);
	m_rangeCircle.setOutlineColor(sf::Color::Green);

	m_aiPath = t_grid.breadthFirst(5, 30);

	int x = t_grid.getCells().at(5).getCentreX();
	int y = t_grid.getCells().at(5).getCentreY();

	m_enemySprite.setPosition(x, y);
}

void AI::draw(sf::RenderWindow& t_window)
{
	if (m_alive)
	{
		t_window.draw(m_rangeCircle);
		t_window.draw(m_enemySprite);
	}
}

void AI::update(Grid &m_grid)
{

	if (m_health <= 0)
	{
		m_alive = false;
	}

	int nextCell = m_aiPath.at(m_aiPath.size() - 1);
	int nextX = m_grid.getCells().at(nextCell).getCentreX();
	int nextY = m_grid.getCells().at(nextCell).getCentreY();

	if (m_enemySprite.getPosition().x > nextX)
	{
		m_enemySprite.move(-1, 0);

	}
	if (m_enemySprite.getPosition().x < nextX)
	{
		m_enemySprite.move(1, 0);

	}
	if (m_enemySprite.getPosition().y > nextY)
	{
		m_enemySprite.move(0, -1);

	}
	if (m_enemySprite.getPosition().y > nextY)
	{
		m_enemySprite.move(0, 1);

	}

	if (m_enemySprite.getPosition().x == nextX && m_enemySprite.getPosition().y == nextY)
	{

		m_aiPath.pop_back();
	}

	m_rangeCircle.setPosition(m_enemySprite.getPosition());

	/*if (m_enemySprite.getPosition().x == randX && m_enemySprite.getPosition().y == randY)
	{
		randX = std::rand() % (ScreenSize::s_width - 200) + 100;
		randY = std::rand() % (ScreenSize::s_height - 200) + 100;
	}

	if (m_enemySprite.getPosition().x > randX)
	{
		setScaleSprite(1);
		m_enemySprite.move(-1, 0);
	}
	else if (m_enemySprite.getPosition().x < randX)
	{
		setScaleSprite(-1);
		m_enemySprite.move(1, 0);
	}

	if (m_enemySprite.getPosition().y > randY)
	{
		m_enemySprite.move(0, -1);
	}
	else if (m_enemySprite.getPosition().y < randY)
	{
		m_enemySprite.move(0, 1);
	}*/

}
