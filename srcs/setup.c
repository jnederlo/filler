/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:16:12 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/02 17:07:09 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_last	*init_last(char *line, t_grid *grid)
{
	t_last	*last;
	int		i;
	int		row;

	last = ft_memalloc(sizeof(t_last));
	row = -1;
	while(row < grid->n_rows)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "O") || ft_strstr(line, "X"))
		{
			i = 0;
			while (line[i])
			{
				line[i] == 'O' ? last->col_O = i - 3 : 0;
				line[i] == 'O' ? last->row_O = row + 1 : 0;
				line[i] == 'X' ? last->col_X = i - 3: 0;
				line[i] == 'X' ? last->row_X = row + 1 : 0;
				i++;
			}
		}
		row++;
	}
	free(line);
	ft_printf("last O = (%d, %d)\n", last->row_O, last->col_O);
	ft_printf("last X = (%d, %d)\n", last->row_X, last->col_X);
	return (last);
}

void	init_map(t_grid *grid, t_last *last)
{
	int	row;
	int	col;

	row = -1;
	col = 0;
	grid->map = malloc(sizeof(long long int *) * (grid->n_rows + 2));
	ft_bzero(grid->map, grid->n_rows + 2);
	while (row++ < (grid->n_rows + 2))
		grid->map[row] = ft_memalloc(sizeof(long long) * (grid->n_cols + 2));
	row = 0;
	init_rows_cols(grid);
	fibonacci(row, col, grid);
	init_players(grid, last);
	print_grid(grid);
}

void	init_rows_cols(t_grid *grid)
{
	grid->last_row = grid->n_rows + 1;
	grid->last_col = grid->n_cols + 1;
	grid->mid_row = grid->n_rows % 2 ? grid->n_rows / 2 + 1 : grid->n_rows / 2;
	grid->mid_col = grid->n_cols % 2 ? grid->n_cols / 2 + 1 : grid->n_cols / 2;
	ft_printf("mid (row, col) = (%d, %d)\n", grid->mid_row, grid->mid_col);
}

void	fibonacci(int row, int col, t_grid *grid)
{
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
	while (row < (grid->n_rows - 1))
	{
		col = 3;
		while (col < (grid->n_cols - 1))
		{
			grid->map[row][col] = fib_filler(row, col, grid);
			col++;
		}
		row++;
	}
}

void	init_players(t_grid *grid, t_last *last)
{
	g_opp_min = -1 * (grid->n_rows * grid->n_rows) * (grid->n_cols * grid->n_cols);
	g_me_max = grid->map[grid->mid_row][grid->mid_col] + 1;
	if (g_opp == 'O')
	{
		grid->map[last->row_O][last->col_O] = g_opp_min;
		grid->map[last->row_X][last->col_X] = g_me_max;
	}
	else
	{
		grid->map[last->row_O][last->col_O] = g_me_max;
		grid->map[last->row_X][last->col_X] = g_opp_min;
	}
}
