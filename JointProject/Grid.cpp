#include "Grid.h"

Grid::Grid()
{
}

void Grid::neighbours(int t_row, int t_col)
{
	for (int direction = 0; direction < 9; direction++) {
		if (direction == 4) continue; // Skip 4, this is ourself.

		int n_row = t_row + ((direction % 3) - 1); // Neighbor row
		int n_col = t_col + ((direction / 3) - 1); // Neighbor column

		// Check the bounds:
		if (n_row >= 0 && n_row < ROWS && n_col >= 0 && n_col < COLS) {

			// A valid neighbor:
			std::cout << "Neighbor: " << n_row << "," << n_col << ": " << arr[n_row][n_col] << std::endl;
		}
	}
}
