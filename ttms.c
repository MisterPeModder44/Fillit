/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:33:59 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/21 12:33:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int			set_ttms(t_fillit *t, int i)
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
	size_t		index;

	index = 0;
	while (index != t->tab_len)
	{
		index = search_empty_case(t, index);
		t->ttms_tab[i]->index = index;
		if (index == ERROR)
			return (FALSE);
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
		++index;
	if (!t->grid[index])
		return (ERROR);
	return (index);
}

t_bool		set_or_check_ttms(t_fillit *t, int i, t_bool b_set_or_check)
{
	int		j;
	int		offset;
	int		id_ofs;

	j = 0;
	while (j < 3)
	{
		offset = t->ttms_tab[i]->offset[j];
		id_ofs = t->ttms_tab[i]->index + offset;
		if (id_ofs >= t->grid_len)
		{
			/*erreur overflow placement*/
			return (FALSE);
		}
		else if (t->grid[id_ofs] != '.' && 
				(t->grid[id_ofs] == '\n' || 
				 t->grid[id_ofs] == '\0'))
		{
			/*erreur placement*/
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
	i = 0;
	while (t->grid[j])
	{
		if (t->grid[j] == c)
			t->grid[j] = '.';
		++j;
	}
}
