/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:16:12 by jnederlo          #+#    #+#             */
/*   Updated: 2017/07/31 14:18:10 by jnederlo         ###   ########.fr       */
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
	grid->map = malloc(sizeof(char *) * grid->n_rows);
	while (row++ < grid->n_rows)
		grid->map[row] = malloc(sizeof(char) * grid->n_cols + 1);
	row = 0;
	while (row < grid->n_rows)
	{
		col = 0;
		while (col < grid->n_cols)
		{
			grid->map[row][col] = '.';
			col++;
		}
		row++;
	}
	print_grid(grid);
}
