/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:18:11 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/22 10:40:44 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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
		flt->ttms_tab[flt->tab_len] = new_ttms;
		++flt->tab_len;
		pr = r;
	}
	if (r == -1)
		return (flt_puterror("An error occured while reading the file!"));
	close(fd);
	return (0);
}
