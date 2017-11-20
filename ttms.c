/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:33:59 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/20 17:49:54 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

void		remove_ttms(t_fillit *t, int i)
{
	char	c;
	int		j;

	c = 'A' + i;
	i = 0;
	while (t->grid[j])
	{
		if (t->grid[j] == c)
			t->grid[j] = '.';
		j++;
	}
}

int			set_ttms(t_fillit *t, int i)
{
	/* Placement du ttms de la gauche vers la droite et du haut vers le bas
	 *  -> Parcourt toute les cases 
	 *  -> Verifie si le ttms rentre en dimmension (width et height)
	 *  -> Fixe les coordonnees temporairement et verifie sans incruster de
	 *  lettre dans la chaine si data peut rentrer dans 

	return (1);
}
