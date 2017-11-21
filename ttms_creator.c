/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttms_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:49:01 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/21 21:58:33 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_bool	check_ttms_buff(char *buff)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			if ((i > 0 && buff[i - 1] != '#') && (i < 19 && buff[i + 1] != '#')
					&& (i / 5 > 0 && buff[i - 5] != '#') && (i / 5 < 3 &&
						buff[i + 5] != '#'))
			{
				flt_puterror("Blocks must all be next to each other!");
				return (FALSE);
			}
		}
		++i;
	}
	return (TRUE);
}

static int		put_offset(char *buff, t_ttms **nt, int *offset, int i)
{
	static int		j;

	if (buff[i] == '#')
	{
		if (*offset > OFFSET_SIZE - 1)
		{
			free(*nt);
			return (flt_puterror("A ttms cannot have more than 4 blocks"));
		}
		else if (*offset > 0)
			(*nt)->offset[*offset] = j + 1;
		++*offset;
		j = 0;
	}
	else
		++j;
	return (0);
}

int				create_ttms(char *buff, t_ttms **nt)
{
	int		i;
	int		offset_index;

	if (!check_ttms_buff(buff) || !(*nt = (t_ttms *)malloc(sizeof(t_ttms))))
		return (flt_puterror("An error occured while creating a tetriminos."));
	i = 0;
	offset_index = 0;
	while (i < 20)
	{
		if (put_offset(buff, nt, &offset_index, i) == ERROR)
			return (ERROR);
		++i;
	}
	return (0);
}
