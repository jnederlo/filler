/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:29:22 by jnederlo          #+#    #+#             */
/*   Updated: 2017/07/30 20:37:50 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int	main()
{
	t_filler	filler;

	setup();
	while (1)
	{
		update_map();
	}
	return (0);
}

char	g_opp;
char	g_me;

void	set_player(char *line)
{
	if (ft_strstr(line, "filler"))
	{
		g_opp = (ft_strstr(line, "$$$ exec p1")) ? 'X' : 'O';
		g_me = (ft_strstr(line, "$$$ exec p1")) ? 'O' : 'X';
	}
}

void	setup()
{
	char	*line;
	int		i;
	t_grid	*grid;

	i = 0;
	while (get_next_line(0, &line))
	{
		set_player(line);
		if (ft_strstr(line, "Plateau"))
		{
			while (line[i])
			{
				while (!ft_isdigit(*line))
					i++;
				if (ft_isdigit(*line))
				{
					grid->n_rows = ft_atoi(&line[i]);
					i += ft_count_digits(grid->n_rows);
					i++;
					grid->n_cols = ft_atoi(&line[i]);
					free (line);
					init_map(grid);
					return ;
				}
			}
		}
	}
}

void	init_map(t_grid *grid)
{
	int			row;
	int			col;
	t_filler	filler;

	row = 0;
	grid->map = malloc((sizeof(char) * grid->n_rows) *
							(sizeof(char) * grid->n_cols + 1);
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
}
