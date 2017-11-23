/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:39:10 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/23 14:43:52 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

int		flt_puterror(char *reason)
{
	if (DEBUG_MODE)
	{
		ft_putstr_fd("\x1b[1;31m\x1b[4mError:\x1b[0m ", STDERR_FILENO);
		ft_putendl_fd(reason, STDERR_FILENO);
	}
	return (ERROR);
}

void	free_memory(t_fillit *flt)
{
	size_t	i;

	i = 0;
	while (i < flt->tab_len)
		free(flt->ttms_tab[i++]);
	free(flt->grid);
}

void	grid_up(t_fillit *t)
{
	if (t->grid_size > 21)
		flt_puterror("t->grid_size too big");
	else
	{
		++(t->grid_size);
		init_grid(t);
		reset_index_ttms(t);
	}
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (nb > (i * i) && i < 65535)
		i++;
	if (i >= 65535)
		return (0);
	else
		return (i);
}
