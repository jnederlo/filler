/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:29:22 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/03 16:47:47 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int	main()
{
	t_grid	*grid;
	char	*line;
	int		i;

	// printf("%d, %d\n", 12, 13);
	// return (0);
	turn = 1;
	i = 0;
	grid = setup();
	get_next_line(0, &line);
	set_piece(line, grid);
	while (turn < 3)
	{
		update_map(grid);
		turn++;
		while (i < (grid->last_row + 2))
		{
			get_next_line(0, &line);
			if (ft_strstr(line, "Piece"))
				set_piece(line, grid);
			i++;
		}
		// clear_piece(grid);
	}
	return (0);
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

void	update_map(t_grid *grid)
{
	char	*line;
	int		row;
	int		col;

	row = 0;
	if ((g_opp_num == 2 && (turn % 2 == 0)) || (g_opp_num == 1 && turn % 2))
	{
		while (get_next_line(0, &line))
		{
			if (ft_strstr(line, "got"))
			{
				line += 11;
				row = ft_atoi(line) + 1;
				line += ft_count_digits(row) + 2;
				col = ft_atoi(line) + 1;
				opp_place(grid, row, col);
				// print_grid(grid);
				return ;
			}
		}
	}
	else
	{
		me_piece(grid);
	}
}

void	me_piece(t_grid *grid)
{
	int	map_row;
	int	map_col;
	int	pos_value;
	int	top_val;

	map_row = 1;
	pos_value = 0;
	top_val = 0;
	while (map_row < grid->last_row)
	{
		map_col = 1;
		while (map_col < grid->last_col)
		{
			if (valid_place(grid, map_row, map_col))
				pos_value = place_value(grid, map_row, map_col);
			if (pos_value > top_val)
			{
				grid->top_row = map_row;
				grid->top_col = map_col;
				top_val = pos_value;
			}
			map_col++;
		}
		map_row++;
	}
	ft_printf("%d %d\n", grid->top_row - 1, grid->top_col - 1);
	me_place(grid);
	// ft_printf("\n\n");
	// print_grid(grid);
}

void	me_place(t_grid *grid)
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

int		place_value(t_grid *grid, int map_row, int map_col)
{
	int	piece_row;
	int	piece_col;
	int	pos_value;
	int	col_start;

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

int		valid_place(t_grid *grid, int map_row, int map_col)
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
			if (grid->map[map_row][map_col] == g_me_max && grid->piece[piece_row][piece_col] == g_me_max)
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

void	opp_place(t_grid *grid, int row, int col)
{
	int	i;
	int	j;
	int	col_start;

	col_start = col;
	i = -1;
	while (++i < (grid->piece_row))
	{
		j = 0;
		col = col_start;
		while (j < (grid->piece_col))
		{
			if (grid->piece[i][j] != 0)
				grid->map[row][col] = g_opp_min;
			j++;
			col++;
		}
		row++;
	}
}

/*
**	setup() will call set_player() which determines if I'm p1 or p2.
**	then I will find the line with "Plateau", and set the num of
**	rows and cols for my map.
*/
t_grid	*setup()
{
	char	*line;
	int		i;
	t_grid	*grid;
	t_last	*last;

	i = 0;
	grid = ft_memalloc(sizeof(t_grid));
	while (get_next_line(0, &line))
	{
		set_player(line);//sets the player
		if (ft_strstr(line, "Plateau"))
		{
			i += 8;
			grid->n_rows = ft_atoi(&line[i]);
			i += ft_count_digits(grid->n_rows) + 1;
			grid->n_cols = ft_atoi(&line[i]);
			// ft_printf("(rows, cols) = (%d, %d)\n", grid->n_rows, grid->n_cols);
			last = init_last(line, grid);//sets the starting coords.
			init_map(grid, last);
			return (grid);
		}
	}
	return (grid);
}

void	set_piece(char *line, t_grid *grid)
{
	int	i;
	int	row;

	i = 6;
	row = -1;
	grid->piece_row = ft_atoi(&line[i]);
	i += ft_count_digits(grid->piece_row) + 1;
	grid->piece_col = ft_atoi(&line[i]);
	grid->piece = malloc(sizeof(long long *) * grid->piece_row);
	ft_bzero(grid->piece, grid->piece_row);
	while (row++ < grid->piece_row)
		grid->piece[row] = ft_memalloc(sizeof(long long) * grid->piece_col);
	init_piece(line, grid, i, row);
}

void	init_piece(char *line, t_grid *grid, int i, int row)
{
	row = 0;
	while (row < grid->piece_row)
	{
		i = 0;
		get_next_line(0, &line);
		if ((g_me_num == 2 && (turn % 2 == 0)) || (g_me_num == 1 && turn % 2))
		{
			while (line[i])
			{
				grid->piece[row][i] = line[i] == '.' ? 0 : g_me_max;
				i++;
			}
		}
		else
		{
			while (line[i])
			{
				grid->piece[row][i] = line[i] == '.' ? 0 : g_opp_min;
				i++;
			}
		}
		row++;
	}
	// free(line);
	// ft_printf("Piece %d, %d:\n", grid->piece_row, grid->piece_col);
	// print_piece(grid);
}

void	set_player(char *line)
{
	if (ft_strstr(line, "jarvis.filler"))//set string to whatever I call my exec.
	{
		g_opp = (ft_strstr(line, "p1")) ? 'X' : 'O';
		g_me = (ft_strstr(line, "p1")) ? 'O' : 'X';
		g_opp_num = g_opp == 'O' ? 1 : 2;
		g_me_num = g_me == 'O' ? 1 : 2;
	}
}
