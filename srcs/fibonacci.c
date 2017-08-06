/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibonacci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:57:26 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/05 22:54:51 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long long int	fib_border(int row, int col, t_grid *grid)
{
	int				last_row;
	int				last_col;

	last_row = grid->last_row;
	last_col = grid->last_col;
	if (row == 0 || col == 0 || row == last_row || col == last_col)
		return (-200000000000);
	else if (row == 1 || col == 1 || row == 2 || col == 2 ||
			row == (last_row - 1) || row == (last_row - 2) ||
			col == (last_col - 1) || col == (last_col - 2))
		return (1);
	else
		return (0);
}

long long int	fib_filler(int row, int col, t_grid *grid)
{
	int	last_row;
	int	last_col;
	int	mid_row;
	int	mid_col;

	last_row = grid->last_row;
	last_col = grid->last_col;
	mid_row = grid->mid_row;
	mid_col = grid->mid_col;
	if (row <= mid_row && col > mid_col)
		return (fib_q2(row, col, grid));
	else if (row > mid_row && col <= mid_col)
		return (fib_q3(row, col, grid));
	else if (row > mid_row && col > mid_col)
		return (fib_q4(row, col, grid));
	else
		return (fib_q1(row, col, grid));
}
