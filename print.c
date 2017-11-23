/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:14:03 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/23 10:39:16 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void			print_grid(t_fillit *t)
{
	ft_putstr(t->grid);
}

void			print_grid_debug(t_fillit *t)
{
	ft_putstr_fd(t->grid, 2);
}
