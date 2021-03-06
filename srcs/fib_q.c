/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib_q.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 10:59:49 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/05 20:49:15 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

long long int		fib_q1(int row, int col, t_grid *grid)
{
	if (col >= row)
		return (grid->map[row - 1][col] + grid->map[row - 2][col]);
	else
		return (grid->map[row][col - 1] + grid->map[row][col - 2]);
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
	if (grid->map[row + 1][col] == 0)
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
