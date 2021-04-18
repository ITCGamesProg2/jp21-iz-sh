#pragma once
#include <iostream>
#include <queue>
class Cell
{
public:
	Cell(int t_cellId = -1) : m_id(t_cellId)
	{
		m_isPassable = true;
	}

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
private:
	int m_id;
	bool m_isMarked{ false };
	bool m_isPassable;
	std::vector<int> m_neighbours;
	int m_parentCellId;
};
