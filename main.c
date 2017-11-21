/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:18:31 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/21 17:32:10 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fillit	flt;

	if (argc == 2)
	{
		init_fillit(&flt);
		init_grid(&flt);
		if (read_ttms(&flt, argv[1]) == 0)
		{
			set_grid_size(&flt, flt.tab_len);
			resolve(&flt, 0);
			print_grid(&flt);
			return (0);
		}
	}
	return (-1);
}
