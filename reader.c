/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:18:11 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/20 17:47:12 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	check_ttms_uniqueness(t_fillit *flt, t_ttms *new_ttms)
{
	return (0);
}

int			read_ttms(t_fillit *flt, char *path)
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
		if (create_ttms(&new_ttms, buff) == -1)
			return (-1);
		if (check_ttms_uniqueness(flt, new_ttms))
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
