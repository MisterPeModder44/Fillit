/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:18:11 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/21 17:28:28 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_bool	check_ttms_uniqueness(t_fillit *flt, t_ttms *new_ttms)
{
	int		i;
	int		j;

	i = 0;
	while (flt->tab_len > 0 && i < flt->tab_len)
	{
		j = 0;
		while (j < OFFSET_SIZE &&
				flt->ttms_tab[i]->offset[j] == new_ttms->offset[j])
			++j;
		if (j == OFFSET_SIZE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int				read_ttms(t_fillit *flt, char *path)
{
	int		fd;
	char	buff[21];
	int		r;
	int		pr;
	t_ttms	*new_ttms;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (flt_puterror("Can't open file!"));
	pr = -1;
	while ((r = read(fd, buff, 21)) > 0)
	{
		if (r < 20 || (r == 21 && buff[20] != '\n') || (pr != -1 && pr != 21))
			return (flt_puterror("Invalid format!"));
		if (create_ttms(buff, &new_ttms) == -1)
			return (-1);
		if (!check_ttms_uniqueness(flt, new_ttms))
			return (flt_puterror("Cannot have two of the same tetriminos!"));
		flt->ttms_tab[flt->tab_len] = new_ttms;
		++flt->tab_len;
		pr = r;
	}
	if (r == -1)
		return (flt_puterror("An error occured while reading the file!"));
	close(fd);
	return (0);
}
