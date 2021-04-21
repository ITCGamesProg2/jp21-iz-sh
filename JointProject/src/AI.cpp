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

	destinationCell = std::rand() % 100;

	while (!t_grid.getCells().at(destinationCell).isPassable())
	{
		destinationCell = std::rand() % 100;
	}

	m_rangeCircle.setRadius(m_spotPlayerRange);
	m_rangeCircle.setPosition(m_enemySprite.getPosition());
	m_rangeCircle.setOrigin(m_rangeCircle.getGlobalBounds().width / 2, m_rangeCircle.getGlobalBounds().height / 2);
	m_rangeCircle.setFillColor(sf::Color::Transparent);
	m_rangeCircle.setOutlineThickness(2u);
	m_rangeCircle.setOutlineColor(sf::Color::Green);

	m_aiPath = t_grid.breadthFirst(5, destinationCell);
	//std::cout << randCell << std::endl;

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

bool AI::update(Grid &m_grid)
{
	if (m_health <= 0)
	{
		m_alive = false;
	}
	
	if (m_alive)
	{

		// get next cell destination in ai's stored path
		int nextCell = m_aiPath.at(m_aiPath.size() - 1);
		int nextX = m_grid.getCells().at(nextCell).getCentreX();
		int nextY = m_grid.getCells().at(nextCell).getCentreY();

		// ai has reached destination , next cell is now the last cell
		if (m_grid.getCells().at(nextCell).id() == destinationCell)
		{
			std::cout << "done" << std::endl;

			// make a new destination
			destinationCell = std::rand() % 100;

			// make sure destination is passable
			while (!m_grid.getCells().at(destinationCell).isPassable())
			{
				destinationCell = std::rand() % 100;
			}

			// generate new ai path, using the final "next" cell as its starting position
			m_aiPath = m_grid.breadthFirst(m_grid.getCells().at(nextCell).id(), destinationCell);
		}

		// get enemy pos
		float x = m_enemySprite.getPosition().x;
		float y = m_enemySprite.getPosition().y;


		// enemy pos is the same as the middle of the cell its heading towards
		if (x == nextX && y == nextY)
		{
			m_aiPath.pop_back();
		}

		// move towards the current destination
		if (m_enemySprite.getPosition().x > nextX)
		{
			m_enemySprite.move(-1, 0);
			setScaleSprite(1);
		}
		if (m_enemySprite.getPosition().x < nextX)
		{
			m_enemySprite.move(1, 0);
			setScaleSprite(-1);
		}
		if (m_enemySprite.getPosition().y > nextY)
		{
			m_enemySprite.move(0, -1);

		}
		if (m_enemySprite.getPosition().y < nextY)
		{
			m_enemySprite.move(0, 1);

		}

		m_rangeCircle.setPosition(m_enemySprite.getPosition());

		return true;
	}
	else
	{
		return false;
	}
	
}

void AI::restart(Grid & t_grid)
{
	m_alive = true;
	m_health = 100;
	
	destinationCell = std::rand() % 100;

	while (!t_grid.getCells().at(destinationCell).isPassable())
	{
		destinationCell = std::rand() % 100;
	}

	m_aiPath = t_grid.breadthFirst(5, destinationCell);

	int x = t_grid.getCells().at(5).getCentreX();
	int y = t_grid.getCells().at(5).getCentreY();

	m_enemySprite.setPosition(x, y);
}

