/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:18:31 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/23 14:03:28 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	free_memory(t_fillit *flt)
{
	size_t	i;

	i = 0;
	while (i < flt->tab_len)
		free(flt->ttms_tab[i++]);
	free(flt->grid);
}

int			main(int argc, char **argv)
{
	t_fillit	flt;

	if (argc == 2)
	{
		init_fillit(&flt);
		if (read_ttms(&flt, argv[1]) == 0)
		{
			set_grid_size(&flt, flt.tab_len);
			init_grid(&flt);
			backtracking(&flt);
			print_grid(&flt);
			free_memory(&flt);
			return (0);
		}
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" [file]");
		return (-2);
	}
	ft_putendl("error");
	return (-1);
}
