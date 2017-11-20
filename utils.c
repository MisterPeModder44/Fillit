/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:39:10 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/20 17:46:34 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

int				flt_puterror(char *reason)
{
	ft_putstr_fd("\x1b[1;31m\x1b[4mError:\x1b[0m ", STDERR_FILENO);
	ft_putendl_fd(reason, STDERR_FILENO);
	return (-1);
}

void			free_fillit(t_fillit *t)
{
	int			i;

	i = 0;
	while (i < 27)
	{
		free(t->ttms_tab[i]);
		i++;
	}
	free(t->grid);
}

void			grid_up(t_fillit *t)
{
	set_grid_size(t, t->tab_len);
	init_grid(t);
}
