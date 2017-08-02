/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:29:22 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/02 13:01:13 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main()
{
	t_grid	*grid;

	grid = setup();
	while (1)
	{
		update_map(grid);
	}
	return (0);
}

void	update_map(t_grid *grid)
{
	char	*line;
	int		i;
	int		row;
	int		col;
	int		j;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (g_opp == 'O' && ft_strstr(line, "got (O)"))
		{
			i = 11;
			row = ft_atoi(&line[i]);
			i += ft_count_digits(row) + 2;
			col = ft_atoi(&line[i]);
			ft_printf("(row, col) = (%d, %d)\n", row, col);
			i = 0;
			while (i < grid->piece_row)
			{
				j = 0;
				while (j < grid->piece_col)
				{
					if (grid->piece[i][j] == 0)
					{
						j++;
						col++;
					}
					else
					{
						grid->map[row][col] = g_opp_min;
						j++;
						col++;
					}
				}
				i++;
				row++;
			}
		}
		print_grid(grid);
		free(line);
		return ;
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
			ft_printf("(rows, cols) = (%d, %d)\n", grid->n_rows, grid->n_cols);
			last = init_last(line, grid);//sets the starting coords.
			init_map(grid, last);
		}
		if (ft_strstr(line, "Piece"))
		{
			set_piece(line, grid);
			free(line);
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
		if (g_me == 'O')
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
	free(line);
	ft_printf("Piece %d, %d:\n", grid->piece_row, grid->piece_col);
	print_piece(grid);
}

void	set_player(char *line)
{
	if (ft_strstr(line, "jarvis.filler"))//set string to whatever I call my exec.
	{
		g_opp = (ft_strstr(line, "p1")) ? 'X' : 'O';
		g_me = (ft_strstr(line, "p1")) ? 'O' : 'X';
		ft_printf("opp = %c, me = %c\n", g_opp, g_me);
	}
}
