#include "Grid.h"

Grid::Grid()
{
	m_cellWidth = ScreenSize::s_width / 10;
	m_cellHeight = ScreenSize::s_height / 10;
}

void Grid::makeGrid()
{
	for (int index = 0; index < 100; index++)
	{
		m_grid.emplace_back(Cell(m_cellWidth, m_cellHeight, index));
	}
	Cell::neighbours(m_grid);
}

void Grid::draw(sf::RenderWindow& t_window)
{
	for (int index = 0; index < 100; index++)
	{
		m_grid.at(index).draw(t_window);
	}
}

void Grid::markImpassableCells(Box& t_box)
{
	int tempLeft;
	int tempTop;
	int tempWidth;
	int tempHeight;

	for (int i = 0; i < t_box.getMaxBox(); i++)
	{
		tempLeft = t_box.getSprite(i).getGlobalBounds().left;
		tempTop = t_box.getSprite(i).getGlobalBounds().top;
		tempWidth = t_box.getSprite(i).getGlobalBounds().width;
		tempHeight = t_box.getSprite(i).getGlobalBounds().height;

		//marking top left corner of sprite
		int cellId = std::floor(tempLeft / m_cellWidth) + (std::floor(tempTop / m_cellHeight) * COLS);
		if (t_box.getAlive(i))
		{
			m_grid.at(cellId).setPassable(false);
		}
		else
		{
			m_grid.at(cellId).setPassable(true);
		}
		//marking top right corner of sprite
		cellId = std::floor((tempLeft + tempWidth) / m_cellWidth) + (std::floor(tempTop / m_cellHeight) * COLS);
		if (t_box.getAlive(i))
		{
			m_grid.at(cellId).setPassable(false);
		}
		else
		{
			m_grid.at(cellId).setPassable(true);
		}
		//marking bottom left corner of sprite
		cellId = std::floor(tempLeft / m_cellWidth) + (std::floor((tempTop + tempHeight) / m_cellHeight) * COLS);
		if (t_box.getAlive(i))
		{
			m_grid.at(cellId).setPassable(false);
		}
		else
		{
			m_grid.at(cellId).setPassable(true);
		}
		//marking top right corner of sprite
		cellId = std::floor((tempLeft + tempWidth) / m_cellWidth) + (std::floor((tempTop + tempHeight) / m_cellHeight) * COLS);
		if (t_box.getAlive(i))
		{
			m_grid.at(cellId).setPassable(false);
		}
		else
		{
			m_grid.at(cellId).setPassable(true);
		}
	}
}

std::vector<int> Grid::breadthFirst(int t_startCellId, int t_destCellId)
{
	for (int i = 0; i < 100; i++)
	{
		m_grid.at(i).colourPath(false);
	}

	bool goalReached = false;
	std::queue<Cell> cellQueue;
	Cell startCell = m_grid.at(t_startCellId);
	cellQueue.emplace(startCell);
	m_grid.at(t_startCellId).setMarked(true);

	while (!cellQueue.empty() && !goalReached)
	{
		for (int i = 0; i < cellQueue.front().neighbours().size() && !goalReached; i++)
		{
			if (m_grid[i].isPassable())
			{
				int childCellid= cellQueue.front().neighbours().at(i);
				Cell& childCell = m_grid.at(childCellid);

				//if we found the destination cell
				if (childCellid == t_destCellId)
				{
					goalReached = true;
					m_grid.at(t_destCellId).setParentCellId(cellQueue.front().id());
				}
				//else if we haven't found the destination cell
				else if (!childCell.isMarked())
				{
					m_grid.at(childCellid).setParentCellId(cellQueue.front().id());
					childCell.setMarked(true);
					cellQueue.push(childCell);
				}
			}
		}

		cellQueue.pop();
	}

	std::vector<int> path;

	int cellIndex = t_destCellId;

	while (m_grid.at(cellIndex).getParentCellId() != -1)
	{
		m_grid.at(cellIndex).colourPath(true);
		path.push_back(cellIndex);

		cellIndex = m_grid.at(cellIndex).getParentCellId();
	}

	path.push_back(cellIndex);

	return path;
}

void Grid::update()
{
	for (int index = 0; index < 100; index++)
	{
		m_grid.at(index).update();
	}
}

void Grid::restart()
{
	for (int i = 0; i < 100; i++)
	{
		m_grid.at(i).setParentCellId(-1);
	}
}


