/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguqye@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:42:04 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/20 15:08:50 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <string.h>

typedef struct	s_ttms
{
	int			x;
	int			y;
	int			width;
	int			height;
	char		*data;
}				t_ttms;

typedef struct	s_fillit
{
	t_ttms		*ttms_tab[27];
	int			tab_len;
	char		*grid;
	int			grid_size;
}				t_fillit;

void			init_fillit(t_fillit *t);
void			init_grid(t_fillit *t);
void			set_tablen(t_fillit *t, int len);
int				ft_sqrt(int nb);
int				read_ttms(t_fillit *flt, char *path);
int				flt_puterror(char *reason);

#endif
