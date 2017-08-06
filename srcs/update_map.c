/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:44:27 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/05 23:18:51 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_piece(char **line, t_grid *grid)
{
	int	i;
	int	row;

	i = 6;
	row = 0;
	grid->piece_row = ft_atoi(&line[0][i]);
	i += ft_count_digits(grid->piece_row) + 1;
	grid->piece_col = ft_atoi(&line[0][i]);
	grid->piece = malloc(sizeof(long long *) * grid->piece_row);
	ft_bzero(grid->piece, grid->piece_row);
	while (row < grid->piece_row)
	{
		grid->piece[row] = ft_memalloc(sizeof(long long) * grid->piece_col);
		row++;
	}
	config_piece(*line, grid, i, row);
}

void	config_piece(char *line, t_grid *grid, int i, int row)
{
	row = 0;
	while (row < grid->piece_row)
	{
		i = 0;
		get_next_line(0, &line);
		if (ft_strstr(line, "Piece"))
			return ;
		while (line[i])
		{
			grid->piece[row][i] = line[i] == '.' ? 0 : g_me_max;
			i++;
		}
		row++;
	}
}

void	take_piece(t_grid *grid)
{
	int				map_row;
	int				map_col;
	long long int	pos_value;
	long long		best_val;

	map_row = 0;
	pos_value = 0;
	best_val = 0;
	while (map_row < grid->last_row)
	{
		map_col = 0;
		while (map_col < grid->last_col)
		{
			if (is_valid(grid, map_row, map_col))
			{
				pos_value = place_value(grid, map_row, map_col);
				// printf("pos_value = %lld\n", pos_value);
			}
			if (pos_value > best_val)
			{
				grid->best_row = map_row;
				grid->best_col = map_col;
				best_val = pos_value;
			}
			map_col++;
		}
		map_row++;
	}
	print_coord(grid);
	// place_piece(grid);
}

void	print_coord(t_grid *grid)
{
	grid->X = grid->best_row - 1;
	grid->Y = grid->best_col - 1;
	ft_printf("%d %d\n", grid->X, grid->Y);
}
