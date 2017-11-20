/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:19:43 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/20 13:48:43 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void			init_fillit(t_fillit *t)
{
	ft_bzero(t->ttms_tab, 27);
	t->tab_len = 0;
	t->grid_size = 0;
	grid = NULL;
}

void			init_grid(
