/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:59:34 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/21 20:52:20 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include <stdio.h>

int			resolve(t_fillit *t, int i)
{
	if (i >= (int)t->tab_len)
		return (i);
	else if (i == -1)
	{
		fprintf(stderr, "RESOLVE : GRID UP\n");
		grid_up(t);
		return (resolve(t, 0));
	}
	else if (set_ttms(t, i))
	{
		fprintf(stderr, "RESOLVE : OK next %d\n", i + 1);
		return (resolve(t, i + 1));
	}
	else
	{
		fprintf(stderr, "RESOLVE : NOK next %d\n", i - 1);
		remove_ttms(t, MOD(i - 1));
		(t->ttms_tab[MOD(i - 1)]->index)++;
		return (resolve(t, i - 1));
	}
}
