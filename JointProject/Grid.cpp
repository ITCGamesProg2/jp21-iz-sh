#include "Grid.h"

Grid::Grid()
{
	
}

void Grid::makeGrid()
{
	for (int index = 0; index < 100; index++)
	{
		m_grid.emplace_back(Cell(index));
	}
	Cell::neighbours(m_grid);
}


