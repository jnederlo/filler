/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:02:00 by jnederlo          #+#    #+#             */
/*   Updated: 2017/07/30 20:37:52 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

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
	char	**map;
	t_start	*last;
}					t_grid;

typedef struct		s_filler
{
	t_grid	*grid;
	t_last	*last;
	char	**piece;
}					t_filler;

extern char			g_opp;
extern char			g_me;



void				set_player(char *line);


#endif
