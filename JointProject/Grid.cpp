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
		m_grid.emplace_back(Cell(index));
	}
	Cell::neighbours(m_grid);
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
		m_grid.at(cellId).setPassable(false);
		//marking top right corner of sprite
		cellId = std::floor((tempLeft + tempWidth) / m_cellWidth) + (std::floor(tempTop / m_cellHeight) * COLS);
		m_grid.at(cellId).setPassable(false);
		//marking bottom left corner of sprite
		cellId = std::floor(tempLeft / m_cellWidth) + (std::floor((tempTop + tempHeight) / m_cellHeight) * COLS);
		m_grid.at(cellId).setPassable(false);
		//marking top right corner of sprite
		cellId = std::floor((tempLeft + tempWidth) / m_cellWidth) + (std::floor((tempTop + tempHeight) / m_cellHeight) * COLS);
		m_grid.at(cellId).setPassable(false);
	}
}


