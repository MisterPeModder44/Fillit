/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttms_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:49:01 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/02 13:28:41 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int		get_links(int i, char *buff)
{
	int		around;

	around = 0;
	if (i > 0 && buff[i - 1] == '#')
		++around;
	if (i < 19 && buff[i + 1] == '#')
		++around;
	if (i / 5 > 0 && buff[i - 5] == '#')
		++around;
	if (i / 5 < 3 && buff[i + 5] == '#')
		++around;
	return (around);
}

static t_bool	check_ttms_buff(char *buff)
{
	int		i;
	int		links;

	i = 0;
	links = 0;
	while (i < 20)
	{
		if (i % 5 < 4 && buff[i] == '#')
			links += get_links(i, buff);
		else if ((i % 5 == 4 && buff[i] != '\n') ||
				(i % 5 < 4 && buff[i] != '.'))
			return (FALSE);
		++i;
	}
	if (links < 6)
		return (FALSE);
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
	(*nt)->index = 0;
	while (i < 20)
	{
		if (put_offset(buff, nt, &offset_index, i) == ERROR)
			return (ERROR);
		++i;
	}
	if (offset_index != 4)
	{
		free(*nt);
		return (flt_puterror("A ttms cannot have less than 4 blocks!"));
	}
	return (0);
}
