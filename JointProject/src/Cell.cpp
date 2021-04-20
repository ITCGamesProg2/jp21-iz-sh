#include "Cell.h"

void Cell::findCentreXandCentreY(int t_cellWidth, int t_cellHeight)
{
	// y is row
	int row;
	// x is col
	int col;

	row = (m_id / 10);
	col = (m_id % 10);

	/*std::cout << row << std::endl;
	std::cout << col << std::endl;

	std::cout << t_cellWidth << std::endl;*/

	m_centreX = (t_cellWidth * col) + (t_cellWidth / 2);

	m_centreY = (t_cellHeight * row) + (t_cellHeight / 2);

	/*std::cout << m_centreX << std::endl;
	std::cout << m_centreY << std::endl;*/
}

void Cell::neighbours(std::vector<Cell>& t_grid)
{
	int t_ROWS = 10;
	int t_COLS = 10;

	for (int row = 0; row < t_ROWS; row++)
	{
		for (int col = 0; col < t_COLS; col++)
		{
			for (int direction = 0; direction < 9; direction++) {
				if (direction == 4) continue; // Skip 4, this is ourself.

				int n_row = row + ((direction % 3) - 1); // Neighbor row
				int n_col = col + ((direction / 3) - 1); // Neighbor column

				// Check the bounds:
				if (n_row >= 0 && n_row < t_ROWS && n_col >= 0 && n_col < t_COLS) {

					int index = row * t_COLS + col;
					int indexOfNeighbour = n_row * t_COLS + n_col;

					t_grid.at(index).addNeighbour(indexOfNeighbour);
				}
			}
		}
	}
}
