/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:02:00 by jnederlo          #+#    #+#             */
/*   Updated: 2017/08/05 19:11:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct		s_grid
{
	int				n_rows;
	int				n_cols;
	int				start_row;
	int				start_col;
	int				last_row;
	int				last_col;
	int				mid_row;
	int				mid_col;
	long long int	**map;
	long long int	**piece;
	int				piece_row;
	int				piece_col;
	int				best_row;
	int				best_col;
	int				X;
	int				Y;
}					t_grid;

/*
**	These are global variables:
*/

char				g_opp;
char				g_me;
int					g_opp_num;
int					g_me_num;
long long int		g_opp_min;
long long int		g_me_max;
int					turn;

/*
**	Functions in ft_filler.c
**	(includes the main())
*/

t_grid				*setup(char **line);
void				update_map(t_grid *grid, char **line);
void				clear_piece(t_grid *grid);


/*
**	Functions in setup.c
*/

void				set_player(char *line);
void				init_map(t_grid *grid);
void				init_rows_cols(t_grid *grid);
void				fibonacci(int row, int col, t_grid *grid);

/*
**	Functions in update_map.c
*/

void				init_piece(char **line, t_grid *grid);
void				config_piece(char *line, t_grid *grid, int i, int row);
void				take_piece(t_grid *grid);
void				print_coord(t_grid *grid);

/*
**	Functions in take_piece.c
*/

int					is_valid(t_grid *grid, int map_row, int map_col);
long long int		place_value(t_grid *grid, int map_row, int map_col);
void				place_piece(t_grid *grid);

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
