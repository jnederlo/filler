/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:16:12 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/03 20:37:46 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// t_last	*init_last(char *line, t_grid *grid)
// {
// 	t_last	*last;
// 	int		i;
// 	int		row;

// 	last = ft_memalloc(sizeof(t_last));
// 	row = -1;
// 	while(row < grid->n_rows)
// 	{
// 		get_next_line(0, &line);
// 		if (ft_strchr(line, g_me))
// 		{
// 			i = 0;
// 			while (line[i])
// 			{
// 				line[i] == g_me ? last->col = i - 3 : 0;
// 				line[i] == g_me ? last->row = row + 1 : 0;
// 				i++;
// 			}
// 		}
// 		row++;
// 	}
// 	// ft_printf("last O = (%d, %d)\n", last->row_O, last->col_O);
// 	// ft_printf("last X = (%d, %d)\n", last->row_X, last->col_X);
// 	return (last);
// }

void	init_map(t_grid *grid)
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
	init_players(grid);
	// print_grid(grid);
}

void	init_rows_cols(t_grid *grid)
{
	grid->last_row = grid->n_rows + 1;
	grid->last_col = grid->n_cols + 1;
	grid->mid_row = grid->n_rows % 2 ? grid->n_rows / 2 + 1 : grid->n_rows / 2;
	grid->mid_col = grid->n_cols % 2 ? grid->n_cols / 2 + 1 : grid->n_cols / 2;
	// ft_printf("mid (row, col) = (%d, %d)\n", grid->mid_row, grid->mid_col);
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

void	init_players(t_grid *grid)
{
	g_opp_min = -1 * (grid->n_rows * grid->n_rows) * (grid->n_cols * grid->n_cols);
	g_me_max = grid->map[grid->mid_row][grid->mid_col] + 1;
	// grid->map[last->row][last->col] = g_me_max;
	// ft_printf("opp = %c, me = %c\n", g_opp, g_me);
	// ft_printf("g_opp_min = %lld\n", g_opp_min);
	// ft_printf("g_me_max = %lld\n", g_me_max);
	// ft_printf("g_opp_num = %d\n", g_opp_num);
	// ft_printf("g_me_num = %d\n", g_me_num);
}
