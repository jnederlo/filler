/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:17:28 by jnederlo          #+#    #+#             */
/*   Updated: 2017/07/31 18:14:44 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_grid(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	while (i < (grid->n_rows + 1))
	{
		j = 0;
		ft_putchar(' ');
		ft_putchar(' ');
		ft_putchar(' ');
		ft_putchar(' ');
		while (j < (grid->n_cols + 1))
		{
			ft_printf("%s\t", ft_itoa(grid->map[i][j]));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
