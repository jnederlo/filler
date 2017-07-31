/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <jnederlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:02:00 by jnederlo          #+#    #+#             */
/*   Updated: 2017/07/30 17:27:57 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

typedef struct		s_start
{
	int	row_O;
	int	col_O;
	int	row_X;
	int	col_X;
}					t_start;

typedef struct		s_grid
{
	int		n_rows;
	int		n_cols;
	t_start	*start;
}					t_grid;

extern char			g_opp;
extern char			g_me;



void				set_player(char *line);


#endif
