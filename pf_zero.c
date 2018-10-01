/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:33:02 by sharris           #+#    #+#             */
/*   Updated: 2018/09/25 15:33:50 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Pads the given string address with zeros.
*/

char	*pf_zero(t_pfdrcv drcv, char **astr)
{
	char *pad;

	if (drcv.oflags & PFO_PAD0)
	{
		if ((int)ft_strlen(*astr) < drcv.mfw)
		{
			pad = gen_padding(drcv.mfw - ft_strlen(*astr), '0');
			if (**astr == '-')
			{
				**astr = '0';
				*pad = '-';
			}
			*astr = ft_strffjoin(&pad, astr);
		}
	}
	return (*astr);
}
