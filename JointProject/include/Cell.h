#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <queue>
class Cell
{
public:
	Cell(int t_cellWidth, int t_cellHeight, int t_cellId = -1) : m_id(t_cellId)
	{
		m_isPassable = true;
		findCentreXandCentreY(t_cellWidth, t_cellHeight);
		m_cellShape.setSize(sf::Vector2f(t_cellWidth, t_cellHeight));
		m_cellShape.setOrigin(m_cellShape.getGlobalBounds().width / 2, m_cellShape.getGlobalBounds().height / 2);
		m_cellShape.setPosition(m_centreX, m_centreY);
		m_cellShape.setFillColor(sf::Color::Transparent);
		m_cellShape.setOutlineThickness(0.5);
		m_cellShape.setOutlineColor(sf::Color::Green);
	}

	void findCentreXandCentreY(int t_cellWidth, int t_cellHeight);
	void draw(sf::RenderWindow& t_window);
	void update();
	static void neighbours(std::vector<Cell>& t_grid);

	/// <summary>
	/// adds a neighbour
	/// </summary>
	/// <param name="t_cellId"></param>
	void addNeighbour(int t_cellId)
	{
		m_neighbours.push_back(t_cellId);
	}

	/// <summary>
	/// if sprite is drawn in a cell, marked impassable
	/// </summary>
	/// <param name="t_imPass"></param>
	void setPassable(bool t_imPass)
	{
		m_isPassable = t_imPass;
	}

	bool isPassable()
	{
		return m_isPassable;
	}
	/// <summary>
	/// returns list of neighbours
	/// </summary>
	/// <returns></returns>
	std::vector<int>& neighbours()
	{
		return m_neighbours;
	}

	void setMarked(bool t_marked)
	{
		m_isMarked = t_marked;
	}

	bool isMarked() const
	{
		return m_isMarked;
	}

	int id() const
	{
		return m_id;
	}

	void setParentCellId(int t_cellId)
	{
		m_parentCellId = t_cellId;
	}

	int getParentCellId()
	{
		return m_parentCellId;
	}

	int getCentreX()
	{
		return m_centreX;
	}

	int getCentreY()
	{
		return m_centreY;
	}

	void colourPath(bool t_onpath)
	{
		m_onPath = t_onpath;
	}

private:
	int m_id;
	int m_centreX;
	int m_centreY;
	bool m_isMarked{ false };
	bool m_isPassable;
	bool m_onPath = false;
	std::vector<int> m_neighbours;
	int m_parentCellId = -1;
	sf::RectangleShape m_cellShape;
};

