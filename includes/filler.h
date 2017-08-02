/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:02:00 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/01 16:28:32 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct		s_last
{
	int	row_O;
	int	col_O;
	int	row_X;
	int	col_X;
}					t_last;

typedef struct		s_grid
{
	int		n_rows;
	int		n_cols;
	int		last_row;
	int		last_col;
	int		mid_row;
	int		mid_col;
	int		**map;
	t_last	*last;
}					t_grid;

typedef struct		s_filler
{
	t_grid	*grid;
	t_last	*last;
	char	**piece;
}					t_filler;

/*
**	These are global variables:
*/

char				g_opp;
char				g_me;

/*
**	Functions in ft_filler.c
**	(includes the main())
*/

void				setup();

/*
**	Functions in setup.c
*/

void				set_player(char *line);
void				init_last(char *line, t_grid *grid);
void				init_rows_cols(t_grid *grid);
void				init_map(t_grid *grid);


void				fibonacci(int row, int col, t_grid *grid);
int					fib_border(int row, int col, t_grid *grid);
int					fib_filler(int row, int col, t_grid *grid);


int					fib_q1(int row, int col, t_grid *grid);
int					fib_q2(int row, int col, t_grid *grid);
int					fib_q3(int row, int col, t_grid *grid);
int					fib_bot_half(int row, int col, t_grid *grid);



/*
**	Functions in print_grid.c
*/

void				print_grid(t_grid *grid);

#endif
