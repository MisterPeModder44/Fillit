/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttms_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:49:01 by yguaye            #+#    #+#             */
/*   Updated: 2017/11/21 13:32:14 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void		suppress_vertical_lines(t_ttms *nt)
{
/*'Removes' blank lines to the right and the left of the ttms.*/
}

static void		suppress_horizontal_lines(t_ttms *nt)
{
/*'Removes' blank lines below and above the ttms.*/
}

int				create_ttms(char *buff, t_ttms **nt)
{
	if (!(*nt = (t_ttms *)malloc(sizeof(t_ttms))))
		return (flt_puterror("An error occured while creating a tetriminos."));
	/*	-=Tttms reading system=-
	 *	*soon!*
	 */
	suppress_horizontal_lines(*nt);
	suppress_vertical_lines(*nt);
	return (0);
}
