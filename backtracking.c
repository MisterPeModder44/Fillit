/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:59:34 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/22 13:15:56 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include <stdio.h>

/*int			resolve(t_fillit *t, int i)
{
	if (i >= (int)t->tab_len)
		return (i);
	else if (i == -1)
	{
		fprintf(stderr, "RESOLVE : GRID UP\n");
		print_grid_debug(t);
		grid_up(t);
		return (resolve(t, 0));
	}
	else if (set_ttms(t, i))
	{
		fprintf(stderr, "RESOLVE : OK next %d\n", i + 1);
		print_grid_debug(t);
		return (resolve(t, i + 1));
	}
	else
	{
		remove_ttms(t, MOD(i - 1));
		(t->ttms_tab[MOD(i - 1)]->index)++;
		fprintf(stderr, "RESOLVE : NOK next %d\n", i - 1);
		print_grid_debug(t);
		return (resolve(t, i - 1));
	}
}*/

int			backtracking(t_fillit *t)
{
	int		i;

	i = 0;
	while (1)
	{
		if (i == -1)
		{
			fprintf(stderr, "RESOLVE : GRID UP\n");
			print_grid_debug(t);
			grid_up(t);
			i = 0;
		}
		else if (i >= (int)t->tab_len)
		{
			return (i);
		}
		else if (set_ttms(t, i))
		{
			fprintf(stderr, "RESOLVE : OK next %d\n", i + 1);
			print_grid_debug(t);
			++i;
		}
		else
		{
			
			remove_ttms(t, MOD(i - 1));
			(t->ttms_tab[MOD(i - 1)]->index)++;
			fprintf(stderr, "RESOLVE : NOK next %d\n", i - 1);
			print_grid_debug(t);
			--i;
		}
	}
}
