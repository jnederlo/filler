/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:16:12 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/01 17:16:05 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_player(char *line)
{
	if (ft_strstr(line, "jarvis.filler"))//set string to whatever I call my exec.
	{
		g_opp = (ft_strstr(line, "p1")) ? 'X' : 'O';
		g_me = (ft_strstr(line, "p1")) ? 'O' : 'X';
		ft_printf("opp = %c, me = %c\n", g_opp, g_me);
	}
}

void	init_last(char *line, t_grid *grid)
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
				line[i] == 'O' ? last->col_O = i - 4 : 0;
				line[i] == 'O' ? last->row_O = row : 0;
				line[i] == 'X' ? last->col_X = i - 4: 0;
				line[i] == 'X' ? last->row_X = row : 0;
				i++;
			}
		}
		row++;
	}
	free(line);
	ft_printf("last O = (%d, %d)\n", last->row_O, last->col_O);
	ft_printf("last X = (%d, %d)\n", last->row_X, last->col_X);
}

void	init_map(t_grid *grid)
{
	int	row;
	int	col;

	row = -1;
	col = 0;
	grid->map = malloc(sizeof(int *) * (grid->n_rows + 2));
	ft_bzero(grid->map, grid->n_rows + 2);
	while (row++ < (grid->n_rows + 2))
		grid->map[row] = ft_memalloc(sizeof(int) * (grid->n_cols + 2));
	row = 0;
	init_rows_cols(grid);
	fibonacci(row, col, grid);
	print_grid(grid);
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

int		fib_border(int row, int col, t_grid *grid)
{
	long int	opp;
	int			last_row;
	int			last_col;

	last_row = grid->last_row;
	last_col = grid->last_col;
	opp = -1 * (grid->n_rows * grid->n_rows) * (grid->n_cols * grid->n_cols);
	if (row == 0 || col == 0 || row == last_row || col == last_col)
		return (opp);
	else if (row == 1 || col == 1 || row == 2 || col == 2 || row == last_row - 1
			|| row == last_row - 2 || col == last_col - 1 || col == last_col - 2)
		return (1);
	else
		return (0);
}

void	init_rows_cols(t_grid *grid)
{
	grid->last_row = grid->n_rows + 1;
	grid->last_col = grid->n_cols + 1;
	grid->mid_row = grid->n_rows % 2 ? grid->n_rows / 2 + 1 : grid->n_rows / 2;
	grid->mid_col = grid->n_cols % 2 ? grid->n_cols / 2 + 1 : grid->n_cols / 2;
	ft_printf("mid (row, col) = (%d, %d)\n", grid->mid_row, grid->mid_col);
}

int		fib_filler(int row, int col, t_grid *grid)
{
	int	last_row;
	int	last_col;
	int	mid_row;
	int	mid_col;

	last_row = grid->last_row;
	last_col = grid->last_col;
	mid_row = grid->mid_row;
	mid_col = grid->mid_col;
	// else if (row == grid->last->row_O && col == grid->last->col_O)
	// 	return (opp);
	if (row <= mid_row && col >= mid_col)
		return (fib_q2(row, col, grid));
	else if (row > mid_row)
		return (fib_bot_half(row, col, grid));
	else
		return (fib_q1(row, col, grid));
}

int		fib_q1(int row, int col, t_grid *grid)
{
	if ((grid->map[row][col - 1] + grid->map[row][col - 2]) <
		(grid->map[row - 1][col] + grid->map[row - 2][col]))
		return (grid->map[row][col - 1] + grid->map[row][col - 2]);
	else
		return (grid->map[row - 1][col] + grid->map[row - 2][col]);
}

int		fib_q2(int row, int col, t_grid *grid)
{
	if (row == grid->mid_row && col > (grid->mid_col + 1))
		return (grid->map[row - 1][col]);
	else if (grid->map[row][col + 1] == 0)
		return (fib_q1(row, col, grid));
	else
		return (grid->map[row][col + 1] + grid->map[row][col + 2]);
}

// int		fib_q3(int row, int col, t_grid *grid)
// {
// 	if (grid->map[row + 1][col] == 0)
// 		return (fib_q1(row, col, grid));
// 	else
// 		return (grid->map[row + 1][col] + grid->map[row + 2][col]);
// }

int		fib_bot_half(int row, int col, t_grid *grid)
{
	if (grid->map[row][col + 1] == 0 || grid->map[row + 1][col] == 0)
	{
		row -= (row - grid->mid_row) * 2;
		return (grid->map[row][col]);
	}
	else
		return (grid->map[row + 1][col] + grid->map[row + 2][col]);
}