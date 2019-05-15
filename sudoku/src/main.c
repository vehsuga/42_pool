/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagushev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:43:18 by vagushev          #+#    #+#             */
/*   Updated: 2018/07/01 22:22:19 by vagushev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		solve_puzzle(int **grid, int row, int column);
int		solve_puzzle_rev(int **grid, int row, int column);

int		is_valid_input(char **argv)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '.' && (argv[i][j] < '1' || argv[i][j] > '9'))
				return (0);
			count++;
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}

void	printout(int **grid)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (grid[i])
	{
		j = 0;
		while (j < 8)
		{
			tmp = '0' + grid[i][j];
			write(1, &tmp, 1);
			write(1, " ", 1);
			j++;
		}
		tmp = '0' + grid[i][j];
		write(1, &tmp, 1);
		write(1, "\n", 1);
		i++;
	}
}

void	parse_input(int **grid, int **grid_cmp, char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[++i])
	{
		grid[i - 1] = (int *)malloc(sizeof(int) * 9);
		grid_cmp[i - 1] = (int *)malloc(sizeof(int) * 9);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '.')
			{
				grid[i - 1][j] = 0;
				grid_cmp[i - 1][j] = 0;
			}
			else
			{
				grid[i - 1][j] = argv[i][j] - '0';
				grid_cmp[i - 1][j] = argv[i][j] - '0';
			}
			j++;
		}
	}
}

int		compare_grids(int **grid, int **grid_cmp)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] != grid_cmp[i][j])
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (grid_cmp[i])
		free(grid_cmp[i++]);
	//free(grid_cmp);
	return (0);
}

int		main(int argc, char **argv)
{
	int **grid;
	int **grid_cmp;
	int i;

	i = 0;
	if (argc != 10 || is_valid_input(argv) != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	grid = (int **)malloc(sizeof(int *) * 9);
	grid_cmp = (int **)malloc(sizeof(int *) * 9);
	parse_input(grid, grid_cmp, argv);
	if (solve_puzzle(grid, 0, 0) == 1 && solve_puzzle_rev(grid_cmp, 0, 0) == 1
			&& compare_grids(grid, grid_cmp) == 0)
		printout(grid);
	else
		write(1, "Error\n", 6);
	i = 0;
	while (grid[i])
		free(grid[i++]);
	free(grid);
	return (0);
}
