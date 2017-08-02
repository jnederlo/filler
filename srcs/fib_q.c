/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib_q's.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:59:49 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/02 11:00:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long long int		fib_q1(int row, int col, t_grid *grid)
{
	if ((grid->map[row][col - 1] + grid->map[row][col - 2]) <
		(grid->map[row - 1][col] + grid->map[row - 2][col]))
		return (grid->map[row][col - 1] + grid->map[row][col - 2]);
	else
		return (grid->map[row - 1][col] + grid->map[row - 2][col]);
}

long long int		fib_q2(int row, int col, t_grid *grid)
{
	if (grid->map[row][col + 1] == 0)
	{
		if (grid->mid_col % 2 == 0)
			col -= (col - grid->mid_col) * 2 - 1;
		else
			col -= (col - grid->mid_col) * 2;
		return (grid->map[row][col]);
	}
	else
		return (grid->map[row][col + 1] + grid->map[row][col + 2]);
}

long long int		fib_q3(int row, int col, t_grid *grid)
{
	if (grid->map[row][col + 1] == 0 && grid->map[row + 1][col] == 0)
	{
		if (grid->mid_row % 2 == 0)
			row -= (row - grid->mid_row) * 2 - 1;
		else
			row -= (row - grid->mid_row) * 2;
		return (grid->map[row][col]);
	}
	else
		return (grid->map[row + 1][col] + grid->map[row + 2][col]);
}

long long int		fib_q4(int row, int col, t_grid *grid)
{
	if (grid->map[row + 1][col] == 0)
	{
		if (grid->mid_col % 2 == 0)
			col -= (col - grid->mid_col) * 2 - 1;
		else
			col -= (col - grid->mid_col) * 2;
		return (grid->map[row][col]);
	}
	else
		return (grid->map[row + 1][col] + grid->map[row + 2][col]);
}
