/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:16:12 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/05 23:42:57 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_player(char *line)
{
	if (ft_strstr(line, "filler"))
	{
		g_opp = (ft_strstr(line, "p1")) ? 'X' : 'O';
		g_me = (ft_strstr(line, "p1")) ? 'O' : 'X';
		g_opp_num = g_opp == 'O' ? 1 : 2;
		g_me_num = g_me == 'O' ? 1 : 2;
	}
}

void	init_map(t_grid *grid)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	grid->map = malloc(sizeof(long long int *) * (grid->n_rows + 100));
	ft_bzero(grid->map, grid->n_rows + 100);
	while (row < (grid->n_rows + 100))
	{
		grid->map[row] = ft_memalloc(sizeof(long long) * (grid->n_cols + 100));
		row++;
	}
	init_rows_cols(grid);
	fibonacci(row, col, grid);
	g_opp_min = -200000000000;
	g_me_max = grid->map[grid->mid_row][grid->mid_col] + 1;
	middle(grid);
	// print_grid(grid);
}

void	init_rows_cols(t_grid *grid)
{
	grid->last_row = grid->n_rows + 1;
	grid->last_col = grid->n_cols + 1;
	grid->mid_row = grid->n_rows % 2 ? grid->last_row / 2 : grid->last_row / 2 + 1;
	grid->mid_col = grid->n_cols % 2 ? grid->last_col / 2 : grid->last_col / 2 + 1;
	// ft_printf("start (row, col) = (%d, %d)\n", grid->start_row, grid->start_col);
	// ft_printf("last (row, col) = (%d, %d)\n", grid->last_row, grid->last_col);
	// ft_printf("mid (row, col) = (%d, %d)\n", grid->mid_row, grid->mid_col);
}

void	fibonacci(int row, int col, t_grid *grid)
{
	row = 0;
	while (row < (grid->n_rows + 2))
	{
		col = 0;
		while (col < (grid->n_cols + 2))
		{
			grid->map[row][col] = fib_border(row, col, grid);
			col++;
		}
		row++;
	}
	row = 3;
	while (row < (grid->last_row - 2))
	{
		col = 3;
		while (col < (grid->last_col - 2))
		{
			grid->map[row][col] = fib_filler(row, col, grid);
			col++;
		}
		row++;
	}
}

void	middle(t_grid *grid)
{
	int row;
	int col;

	row = 1;
	while (row < grid->last_row)
	{
		col = 1;
		while (col < (grid->last_col))
		{
			if (row == grid->mid_row)
				grid->map[row][col] = g_me_max - (grid->n_rows - 5);
			else if (col == grid->mid_col)
				grid->map[row][col] = g_me_max - (grid->n_cols - 20);
			col++;
		}
		row++;
	}
}
