/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:33:59 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/22 13:30:34 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include <stdio.h>

t_bool		set_ttms(t_fillit *t, int i)
{
	int		index;

	index = t->ttms_tab[i]->index;
	while (index < (int)t->grid_len)
	{
		index = search_empty_case(t, index);
		if (index == ERROR)
		{
			t->ttms_tab[i]->index = 0;
			return (FALSE);
		}
		t->ttms_tab[i]->index = index;
		if (set_or_check_ttms(t, i, CHECK))
		{
			if (!set_or_check_ttms(t, i, SET))
				flt_puterror("can't set ttms");
			return (TRUE);
		}
		++index;
	}
	t->ttms_tab[i]->index = 0;
	return (FALSE);
}

int			search_empty_case(t_fillit *t, size_t index)
{
	while (t->grid[index] && t->grid[index] != '.')
		index++;
	if (!t->grid[index])
		return (ERROR);
	return (index);
}


t_bool		set_or_check_ttms(t_fillit *t, int i, t_bool b_set_or_check)
{
	size_t		j;
	size_t		offset;
	size_t		id_ofs;

	j = 0;
	id_ofs = t->ttms_tab[i]->index;
	while (j < 4)
	{
		offset = t->ttms_tab[i]->offset[j];
		offset = ((offset > 1) ? (offset + (t->grid_size - 4)) : offset);
		id_ofs += offset;
		if (id_ofs >= t->grid_len || t->grid[id_ofs] != '.')
			return (FALSE);
		else if (b_set_or_check == SET)
			t->grid[id_ofs] = 'A' + i;
		++j;
	}
	return (TRUE);
}

void		remove_ttms(t_fillit *t, int i)
{
	char	c;
	int		j;

	c = 'A' + i;
	j = 0;
	while (t->grid[j])
	{
		if (t->grid[j] == c)
			t->grid[j] = '.';
		++j;
	}
}
