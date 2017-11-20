/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:59:34 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/20 17:32:31 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int			resolve(t_fillit *t, int i)
{
	if (i > t->tab_len)
		return (i);
	else if (i == -1)
	{
		grid_up(t);
		return (resolve(t, 0));
	}
	if (set_ttms(t, i))
	{
		return (resolve(t, i + 1));
	}
	else
	{
		remove_ttms(t, i - 1);
		return (resolve(t, i - 1));
	}
}
