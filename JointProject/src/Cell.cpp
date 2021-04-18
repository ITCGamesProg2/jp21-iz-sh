#include "Cell.h"

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
