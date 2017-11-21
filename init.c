/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:19:43 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/21 17:08:05 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include "stdlib.h"

void			init_fillit(t_fillit *t)
{
	int			i;

	i = 0;
	while (i < 27)
	{
		t->ttms_tab[i] = NULL;
		++i;
	}
	t->tab_len = 0;
	t->grid_size = 0;
	t->grid_len = 0;
	t->grid = NULL;
}

void			init_grid(t_fillit *t)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (t->grid)
		free(t->grid);
	t->grid = ft_strnew((t->grid_size * t->grid_size) + t->grid_size + 1);
	t->grid_len = ft_strlen(t->grid);
	while (i < t->grid_size)
	{
		while (j < t->grid_size)
		{
			t->grid[((t->grid_size + 1) * i) + j] = '.';
			++j;
		}
		t->grid[((t->grid_size + 1) * i) + j] = '\n';
		j = 0;
		++i;
	}
}

void			set_tablen(t_fillit *t, int len)
{
	t->tab_len = len;
	set_grid_size(t, t->tab_len);
}

void			set_grid_size(t_fillit *t, int len)
{
	t->grid_size = ft_sqrt(len * 4);
	if (!t->grid_size)
		flt_puterror("Invalid grid size");
}

