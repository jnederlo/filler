/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:29:22 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/01 15:12:59 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main()
{
	// t_filler	filler;

	setup();
	// while (1)
	// {
	// 	update_map();
	// }
	return (0);
}







/*
**	setup() will call set_player() which determines if I'm p1 or p2.
**	then I will find the line with "Plateau", and set the num of
**	rows and cols for my map.
*/
void	setup()
{
	char	*line;
	int		i;
	t_grid	*grid;

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
			init_last(line, grid);//sets the starting coords.
			init_map(grid);
			return ;
		}
	}
}
