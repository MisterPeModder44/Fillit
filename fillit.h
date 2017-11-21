/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguqye@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:42:04 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/21 13:09:23 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

# define		TRUE				1
# define		FALSE				0
# define		ERROR				-1
# define		CHECK				0
# define		SET					1
# define		MOD(x)				((x < 0) ? 0 : x)

typedef unsigned char	t_bool;

typedef struct		s_ttms
{
	size_t			index;
	/*int			width;*/
	/*int			height;*/
	char			offset[3];
}					t_ttms;

typedef struct		s_fillit
{
	t_ttms			*ttms_tab[27];
	size_t			tab_len;
	char			*grid;
	size_t			grid_size;
	size_t			grid_len;
}					t_fillit;

void				init_fillit(t_fillit *t);
void				init_grid(t_fillit *t);
void				set_tablen(t_fillit *t, int len);
int					ft_sqrt(int nb);
int					read_ttms(t_fillit *flt, char *path);
int					create_ttms(char *buff, t_ttms **nt);
int					flt_puterror(char *reason);
void				free_fillit(t_fillit *t);
void				set_grid_size(t_fillit *t, int len);
void				grid_up(t_fillit *t);
int					set_ttms(t_fillit *t, int i);
int					search_empty_case(t_fillit *t, size_t index);
t_bool				set_or_check_ttms(t_fillit *t, int i, t_bool b_set_check);
void				remove_ttms(t_fillit *t, size_t i);

#endif
