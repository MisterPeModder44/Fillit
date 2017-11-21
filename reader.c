/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:18:11 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/21 13:29:19 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_bool	check_ttms_uniqueness(t_fillit *flt, t_ttms *new_ttms)
{
	/*
	 *	To update with the new ttms storage method,
	 *	when I figure out what pierre did to it...
	 */
	int		i;

	i = 0;
	while (flt->tab_len > 0 && i < flt->tab_len)
	{
		if (ft_strequ(flt->ttms_tab[i]->data, new_ttms->data))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int				read_ttms(t_fillit *flt, char *path)
{
	int		fd;
	char	buff[21];
	int		ret;
	int		pret;
	t_ttms	*new_ttms;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (flt_puterror("Can't open file!"));
	while ((ret = read(fd, buff, 21)) > 0)
	{
		if (ret < 20 || (ret == 21 && buff[20] != '\n') || pret != 21)
			return (flt_puterror("Invalid format!"));
		if (create_ttms(buff, &new_ttms) == -1)
			return (-1);
		if (!check_ttms_uniqueness(flt, new_ttms))
			return (flt_puterror("Cannot have two of the same tetriminos!"));
		flt->ttms_tab[flt->tab_len] = new_ttms;
		++flt->tab_len;
		pret = ret;
	}
	if (ret == -1)
		return (flt_puterror("An error occured while reading the file!"));
	close(fd);
	return (0);
}
