/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagushev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 14:02:32 by vagushev          #+#    #+#             */
/*   Updated: 2018/07/01 17:12:36 by vagushev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		solve_puzzle(int **grid, int row, int column);
int		solve_puzzle_rev(int **grid, int row, int column);

int		is_valid(int **grid, int row, int column, int candidate)
{
	int block_row;
	int block_column;
	int i;

	i = 0;
	block_row = (row / 3) * 3;
	block_column = (column / 3) * 3;
	while (i < 9)
	{
		if (grid[row][i] == candidate)
			return (0);
		if (grid[i][column] == candidate)
			return (0);
		if (grid[block_row + (i % 3)][block_column + (i / 3)] == candidate)
			return (0);
		i++;
	}
	return (1);
}

int		rec_helper_rev(int **grid, int row, int column)
{
	int i;

	i = 9;
	while (i > 0)
	{
		if (is_valid(grid, row, column, i) == 1)
		{
			grid[row][column] = i;
			if ((column + 1) < 9)
				if (solve_puzzle_rev(grid, row, column + 1) == 1)
					return (1);
				else
					grid[row][column] = 0;
			else if ((row + 1) < 9)
				if (solve_puzzle_rev(grid, row + 1, 0) == 1)
					return (1);
				else
					grid[row][column] = 0;
			else
				return (1);
		}
		i--;
	}
	return (0);
}

int		rec_helper(int **grid, int row, int column)
{
	int i;

	i = 1;
	while (i < 10)
	{
		if (is_valid(grid, row, column, i) == 1)
		{
			grid[row][column] = i;
			if ((column + 1) < 9)
				if (solve_puzzle(grid, row, column + 1) == 1)
					return (1);
				else
					grid[row][column] = 0;
			else if ((row + 1) < 9)
				if (solve_puzzle(grid, row + 1, 0) == 1)
					return (1);
				else
					grid[row][column] = 0;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int		solve_puzzle(int **grid, int row, int column)
{
	if (row < 9 && column < 9)
		if (grid[row][column] != 0)
			if ((column + 1) < 9)
				return (solve_puzzle(grid, row, column + 1));
			else if ((row + 1) < 9)
				return (solve_puzzle(grid, row + 1, 0));
			else
				return (1);
		else
			return (rec_helper(grid, row, column));
	else
		return (1);
}

int		solve_puzzle_rev(int **grid, int row, int column)
{
	if (row < 9 && column < 9)
		if (grid[row][column] != 0)
			if ((column + 1) < 9)
				return (solve_puzzle_rev(grid, row, column + 1));
			else if ((row + 1) < 9)
				return (solve_puzzle_rev(grid, row + 1, 0));
			else
				return (1);
		else
			return (rec_helper_rev(grid, row, column));
	else
		return (1);
}
