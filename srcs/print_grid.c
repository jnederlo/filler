/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:17:28 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/05 15:15:06 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_grid(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	while (i < (grid->n_rows + 30))
	{
		j = 0;
		// ft_printf("%d", i);
		// ft_putchar(' ');
		// ft_putchar(' ');
		// ft_putchar(' ');
		while (j < (grid->n_cols + 30))
		{
			ft_printf("%s\t", ft_itoa(grid->map[i][j]));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_piece(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	while (i < grid->piece_row)
	{
		j = 0;
		while (j < grid->piece_col)
		{
			ft_printf("%s\t", ft_itoa(grid->piece[i][j]));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
