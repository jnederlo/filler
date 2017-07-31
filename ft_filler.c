/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:29:22 by jnederlo          #+#    #+#             */
/*   Updated: 2017/07/30 17:51:31 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int	main()
{
	char	*line;
	int		i;
	t_grid	grid;

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
					grid.n_rows = ft_atoi(&line[i]);
					printf("%i\n", grid.n_rows);
					i += ft_count_digits(grid.n_rows);
					i++;
					grid.n_cols = ft_atoi(&line[i]);
					printf("%i\n", grid.n_cols);
				}
			}
		}
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