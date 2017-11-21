/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:33:59 by pleroux           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/11/21 17:24:18 by pleroux          ###   ########.fr       */
=======
/*   Updated: 2017/11/21 17:07:51 by yguaye           ###   ########.fr       */
>>>>>>> d3023d532292d4902f23d2dc7da8589a3a80a3b4
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

t_bool		set_ttms(t_fillit *t, int i)
{
	/* Placement du ttms de la gauche vers la droite et du haut vers le bas
	 *  -> Parcourt toute les cases 
	 *  -> ?? Verifie si le ttms rentre en dimmension (width et height) ??
	 *  -> Fixe les coordonnees temporairement et verifie sans incruster de
	 *  lettre dans la chaine si data peut rentrer dans la grid :
	 *  	-> si oui : copie de data dans grid en fixant les coordonnees dans
	 *  	la structure.
	 *  	-> si non : continue a parcourir les autres cases
	 */
	int		index;

	index = 0;
	while (index != (int)t->tab_len)
	{
		index = search_empty_case(t, index);
		if (index == ERROR)
			return (FALSE);
		t->ttms_tab[i]->index = index;
		if (set_or_check_ttms(t, i, CHECK))
		{
			/*ok placement*/
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

#include <stdio.h>

t_bool		set_or_check_ttms(t_fillit *t, int i, t_bool b_set_or_check)
{
	size_t		j;
	size_t		offset;
	size_t		id_ofs;

	j = 0;
	id_ofs = t->ttms_tab[i]->index;
	printf("%lu\n", id_ofs);
	while (j < 3)
	{
		offset = t->ttms_tab[i]->offset[j];
		offset = ((offset > 1) ? (offset + (t->grid_size - 4)) : offset);
		id_ofs += offset;
		printf("%lu\n", id_ofs);
		if (id_ofs >= t->grid_len || t->grid[id_ofs] != '.')
		{
			return (FALSE);
		}
		else if (b_set_or_check == SET)
			t->grid[id_ofs] = 'A' + i;
		++j;
	}
	/*ok placement*/
	return (TRUE);
}

void		remove_ttms(t_fillit *t, size_t i)
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
