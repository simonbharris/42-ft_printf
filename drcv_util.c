/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drcv_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 06:37:02 by sharris           #+#    #+#             */
/*   Updated: 2018/09/17 06:37:14 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** initpfdir -- initialize a pfdir struct type.
** Initializes a pfdir struct, setting all values to defaults.
*/

t_pfdrcv	initpfdir(void)
{
	t_pfdrcv drcv;

	drcv.oflags = 0;
	drcv.mfw = 0;
	drcv.type = '\0';
	return (drcv);
}

void		skip_atoi(const char **str)
{
	if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
			*str += 1;
		*str -= 1;
	}
}
