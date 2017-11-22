/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguqye@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:42:04 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/22 13:29:16 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

# define ERROR			-1
# define CHECK			0
# define SET			1
# define MOD(x)			((x < 0) ? 0 : x)
# define DEF_SIZE		4
# define OFFSET_SIZE	4
# define TTMS_TAB		27
# define DEBUG_MODE		1

typedef enum		e_bool
{
	TRUE = 1,
	FALSE = 0,
}					t_bool;

typedef struct		s_ttms
{
	size_t			index;
	char			offset[OFFSET_SIZE];
}					t_ttms;

typedef struct		s_fillit
{
	t_ttms			*ttms_tab[TTMS_TAB];
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
t_bool				set_ttms(t_fillit *t, int i);
int					search_empty_case(t_fillit *t, size_t index);
t_bool				set_or_check_ttms(t_fillit *t, int i, t_bool b_set_check);
void				remove_ttms(t_fillit *t, int i);
void				print_grid(t_fillit *t);
void				reset_index_ttms(t_fillit *t);
void				print_grid_debug(t_fillit *t);
int					backtracking(t_fillit *t);

#endif
