/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:59:34 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/22 13:28:55 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include <stdio.h>

int			backtracking(t_fillit *t)
{
	int		i;

	i = 0;
	while (1)
	{
		if (i == -1)
		{
			grid_up(t);
			i = 0;
		}
		else if (i >= (int)t->tab_len)
			return (i);
		else if (set_ttms(t, i))
			++i;
		else
		{
			remove_ttms(t, MOD(i - 1));
			(t->ttms_tab[MOD(i - 1)]->index)++;
			--i;
		}
	}
}
