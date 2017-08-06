/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:48:25 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/05 18:56:34 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_valid(t_grid *grid, int map_row, int map_col)
{
	int	num;
	int	piece_row;
	int	piece_col;
	int	col_start;

	num = 0;
	piece_row = 0;
	col_start = map_col;
	while (piece_row < grid->piece_row)
	{
		piece_col = 0;
		map_col = col_start;
		while (piece_col < grid->piece_col)
		{
			if (grid->map[map_row][map_col] == g_me_max &&
					grid->piece[piece_row][piece_col] == g_me_max)
				num++;
			piece_col++;
			map_col++;
		}
		piece_row++;
		map_row++;
	}
	if (num != 1)
		return (0);
	return (1);
}

long long	place_value(t_grid *grid, int map_row, int map_col)
{
	int				piece_row;
	int				piece_col;
	long long int	pos_value;
	int				col_start;

	piece_row = 0;
	pos_value = 0;
	col_start = map_col;
	while (piece_row < grid->piece_row)
	{
		piece_col = 0;
		map_col = col_start;
		while (piece_col < grid->piece_col)
		{
			if (grid->piece[piece_row][piece_col] == g_me_max)
				pos_value += grid->map[map_row][map_col];
			piece_col++;
			map_col++;
		}
		piece_row++;
		map_row++;
	}
	return (pos_value);
}

void		place_piece(t_grid *grid)
{
	int	i;
	int	j;
	int	col_start;

	col_start = grid->top_col;
	i = -1;
	while (++i < (grid->piece_row))
	{
		j = 0;
		grid->top_col = col_start;
		while (j < (grid->piece_col))
		{
			if (grid->piece[i][j] != 0)
				grid->map[grid->top_row][grid->top_col] = g_me_max;
			j++;
			grid->top_col++;
		}
		grid->top_row++;
	}

}
