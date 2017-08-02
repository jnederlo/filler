/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:02:00 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/02 12:55:46 by jnederlo         ###   ########.fr       */
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
	int				n_rows;
	int				n_cols;
	int				last_row;
	int				last_col;
	int				mid_row;
	int				mid_col;
	long long int	**map;
	long long int	**piece;
	int				piece_row;
	int				piece_col;
	t_last			*last;
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
long long int		g_opp_min;
long long int		g_me_max;

/*
**	Functions in ft_filler.c
**	(includes the main())
*/

t_grid				*setup();
void				update_map(t_grid *grid);
void				set_player(char *line);
void				set_piece(char *line, t_grid *grid);
void				init_piece(char *line, t_grid *grid, int i, int row);

/*
**	Functions in setup.c
*/

t_last				*init_last(char *line, t_grid *grid);
void				init_map(t_grid *grid, t_last *last);
void				init_rows_cols(t_grid *grid);
void				fibonacci(int row, int col, t_grid *grid);
void				init_players(t_grid *grid, t_last *last);

/*
**	Functions in fibonacci.c
*/

long long int		fib_border(int row, int col, t_grid *grid);
long long int		fib_filler(int row, int col, t_grid *grid);

/*
**	Functions in fib_q.c
*/

long long int		fib_q1(int row, int col, t_grid *grid);
long long int		fib_q2(int row, int col, t_grid *grid);
long long int		fib_q3(int row, int col, t_grid *grid);
long long int		fib_q4(int row, int col, t_grid *grid);

/*
**	Functions in print_grid.c
*/

void				print_grid(t_grid *grid);
void				print_piece(t_grid *grid);

#endif
