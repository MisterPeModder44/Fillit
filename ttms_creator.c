/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttms_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:49:01 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/21 15:04:54 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_bool	check_ttms(t_ttms *nt)
{
	return (0);
}

int				create_ttms(char *buff, t_ttms **nt)
{
	int		i;
	int		j;
	int		offset_index;

	if (!(*nt = (t_ttms *)malloc(sizeof(t_ttms))))
		return (flt_puterror("An error occured while creating a tetriminos."));
	i = 0;
	j = 0;
	offset_index = -1;
	while (i < 21)
	{
		if (buff[i] == '#')
		{
			if (offset_index > 2)
			{
				free(*nt);
				return (flt_puterror("A ttms cannot have more than 4 blocks"));
			}
			else if (offset_index != -1)
				(*nt)->offset[offset_index] = j;
			++offset_index;
			j = 0;
		}
		else
			j++;
		++i;
	}
	if (!check_ttms(*nt))
	{
		free(*nt);
		return (ERROR);
	}
	return (0);
}
