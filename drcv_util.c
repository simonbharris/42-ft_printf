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
	drcv.pv = 0;
	return (drcv);
}

/*
** skip_atoi
** Skips over positive atoi values.
*/

void		skip_atoi(const char **str)
{
	if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
			*str += 1;
		*str -= 1;
	}
}

/*
** gen_padding
** Generates a malloced string of len length
** String contents are filled with c characters.
** null-terminated.
*/

char *gen_padding(int len, int c)
{
	char *out;

	out = ft_strnew(len);
	while (len-- > 0)
		out[len] = c;
	return (out);
}
