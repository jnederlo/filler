/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:16:12 by jnederlo          #+#    #+#             */
/*   Updated: 2017/07/31 20:36:48 by jnederlo         ###   ########.fr       */
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
	// grid->map = malloc((grid->n_rows + 1) * sizeof(int *) + ((grid->n_rows + 1) * ((grid->n_cols + 1) * sizeof(int))));
	grid->map = malloc(sizeof(int *) * grid->n_rows + 2);
	while (row++ < (grid->n_rows + 2))
		grid->map[row] = malloc(sizeof(int) * grid->n_cols + 2);
	row = 0;
	while (row < (grid->n_rows + 1))
	{
		col = 0;
		while (col < (grid->n_cols + 2))
		{
			grid->map[row][col] = fibonacci(row, col, grid);
			col++;
		}
		row++;
	}
	print_grid(grid);
}

int		fibonacci(int row, int col, t_grid *grid)
{
	long int	opp;
	long int	num;
	int			last_row;
	int			last_col;

	last_row = grid->n_rows + 1;
	last_col = grid->n_cols + 1;
	opp = -1 * (grid->n_rows * grid->n_rows) * (grid->n_cols * grid->n_cols);
	if (row == 0 || col == 0 || row == last_row + 1 || col == last_col + 1)
		return (opp);
	// else if (row == grid->last->row_O && col == grid->last->col_O)
	// 	return (opp);
	else if (row == 1 || col == 1 || row == 2 || col == 2 || row == last_row || row == last_row - 1 || col == last_col || col == last_col - 1)
		return (1);
	else
	{
		if (row <= col)
			num = grid->map[row - 1][col] + grid->map[row - 2][col];
		else
			num = grid->map[row][col - 1] + grid->map[row][col - 2];
	}
	return (num);
}
