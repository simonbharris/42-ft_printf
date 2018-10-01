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

static void prepend_altx(t_pfdrcv drcv, char **astr)
{
	if (drcv.oflags & PFO_CAPS)
		*astr = ft_strcfjoin("0X", astr);
	else
		*astr = ft_strcfjoin("0x", astr);
}

static void	add_zpad(t_pfdrcv drcv, char **astr, char **hold)
{
	if (!(drcv.oflags & PFO_DIOUXB && ft_strlen(*astr) + drcv.pv >= drcv.mfw))
	{
		*hold = gen_padding (drcv.mfw - ft_strlen(*astr), '0');
		if (**astr == '-')
		{
			**astr = '0';
			**hold = '-';
		}
		*astr = ft_strffjoin(hold, astr);
	}
}

/*
** Pads the given string address with zeros.
*/

char	*pf_zero(t_pfdrcv drcv, char **astr)
{
	char *pad;

	if ((!(drcv.oflags & PFO_LPD))
		&& drcv.oflags & PFO_PAD0 && (int)ft_strlen(*astr) < drcv.mfw)
	{
		if (drcv.oflags & PFO_X && drcv.oflags & PFO_ALT)
		{
			if (drcv.mfw - 2 > (int)ft_strlen(*astr))
			{
				pad = gen_padding(drcv.mfw - 2 - (int)ft_strlen(*astr), '0');
				*astr = ft_strffjoin(&pad, astr);
				prepend_altx(drcv, astr);
			}
			else
				prepend_altx(drcv, astr);
		}
		else
			add_zpad(drcv, astr, &pad);
	}
	return (*astr);
}
