/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:29:22 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/05 19:08:37 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int	main()
{
	t_grid	*grid;
	char	*line;

	turn = 1;
	grid = setup(&line);
	while (1)
	{
		update_map(grid, &line);
		clear_piece(grid);
		turn++;
	}
	return (0);
}

t_grid	*setup(char **line)
{
	int		i;
	t_grid	*grid;

	i = 0;
	grid = ft_memalloc(sizeof(t_grid));
	get_next_line(0, line);
	set_player(*line);
	get_next_line(0, line);
	(*line) += 8;
	grid->n_rows = ft_atoi(*line);
	(*line) += ft_count_digits(grid->n_rows) + 1;
	grid->n_cols = ft_atoi(*line);
	init_map(grid);
	(*line) -= (8 + ft_count_digits(grid->n_rows) + 1);
	return (grid);
}

void	update_map(t_grid *grid, char **line)
{
	// char	*line;
	int		row;
	int		col;

	row = -1;
	if (turn > 1)
		get_next_line(0, line);
	while (row < grid->n_rows)
	{
		get_next_line(0, line);
		col = 0;
		while (line[0][col])
		{
			if (line[0][col] == g_opp || line[0][col] == (g_opp + 32))
				grid->map[grid->start_row + row][grid->start_col + col - 4] = g_opp_min;
			else if (line[0][col] == g_me || line[0][col] == (g_me + 32))
				grid->map[grid->start_row + row][grid->start_col + col - 4] = g_me_max;
			col++;
		}
		row++;
	}
	get_next_line(0, line);
	init_piece(line, grid);
	take_piece(grid);
}

void	clear_piece(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->piece_row)
	{
		free(grid->piece[i]);
		i++;
	}
	free(grid->piece);
}
