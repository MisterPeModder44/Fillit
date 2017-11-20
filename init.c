/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:19:43 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/20 14:57:13 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include "stdlib.h"

void			init_fillit(t_fillit *t)
{
	ft_bzero(t->ttms_tab, 27);
	t->tab_len = 0;
	t->grid_size = 0;
	t->grid = NULL;
}

void			init_grid(t_fillit *t)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!t->grid)
		free(t->grid);
	t->grid = ft_strnew((t->grid_size * t->grid_size) + t->grid_size + 1);
	while (i < t->grid_size)
	{
		while (j < t->grid_size)
		{
			t->grid[((t->grid_size + 1) * i) + j] = '.';
			j++;
		}
		t->grid[((t->grid_size + 1) * i) + j] = '\n';
		j = 0;
		i++;
	}
}

void			set_tablen(t_fillit *t, int len)
{
	t->tab_len = len;
	t->grid_size = ft_sqrt(t->tab_len * 4);
	if (!t->grid_size)
		flt_puterror("unvalid grid size");
}
