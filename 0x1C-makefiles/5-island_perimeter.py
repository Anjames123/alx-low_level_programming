#!/usr/bin/python3
"""Module that calculates the perimeter of an island in a grid."""


def num_water_neighbors(grid, i, j):
    """
    Returns the count of neighboring water cells around a given cell in the grid.

    Args:
        grid (list[list[int]]): The grid representing the island.
        i (int): The row index of the current cell.
        j (int): The column index of the current cell.

    Returns:
        int: The count of neighboring water cells.
    """
    count = 0

    if i <= 0 or not grid[i - 1][j]:
        count += 1
    if j <= 0 or not grid[i][j - 1]:
        count += 1
    if j >= len(grid[i]) - 1 or not grid[i][j + 1]:
        count += 1
    if i >= len(grid) - 1 or not grid[i + 1][j]:
        count += 1

    return count


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in the grid.

    Args:
        grid (list[list[int]]): The grid representing the island.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                perimeter += num_water_neighbors(grid, i, j)

    return perimeter
