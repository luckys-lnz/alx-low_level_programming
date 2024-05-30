#!/usr/bin/python3
"""
This module defines a function that calculates the perimeter of an island
described in a 2D grid.
"""

def island_perimeter(grid):
    """
    Calculates the perimeter of an island described in a 2D grid.

    Args:
        grid (list of list of integers): A 2D grid representing the island.
            0 represents a water zone, and 1 represents a land zone.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] ==1:
                # check left, right, up and down.
                if c == 0 or grid[r][c-1] == 0:
                    perimeter += 1
                if c == cols -1 or grid[r][c+1] == 0:
                    perimeter += 1
                if r == 0 or grid[r-1][c] == 0:
                    perimeter += 1
                if r == rows-1 or grid[r+1][c] == 0:
                    perimeter +=1
    return perimeter