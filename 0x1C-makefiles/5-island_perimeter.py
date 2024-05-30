#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimiter of an island.
    The grid represents water by 0 and land by 1.
    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in grid.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] ==1:
                """check left, right, up and down."""
                if c == 0 or grid[r][c-1] == 0:
                    perimeter += 1
                if c == cols -1 or grid[r][c+1] == 0:
                    perimeter += 1
                if r == 0 or grid[r-1][c] == 0:
                    perimeter += 1
                if r == rows-1 or grid[r+1][c] == 0:
                    perimeter +=1
    return perimeter