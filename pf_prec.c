/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 08:24:53 by sharris           #+#    #+#             */
/*   Updated: 2018/09/23 08:24:55 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** is_zero
** Since my atoi doesn't work with hex, this just sees if the
** string only contains zeros, if it does, the represented value is zero.
*/

static int is_zero(char *str)
{
	while (*str)
		if (*str++ != '0')
			return (0);
	return (1);
}

/*
** xp_prepend
** adds 0x or 0X to the beginning of p and xX datatypes when appropriate.
*/

static char *xp_prepend(t_pfdrcv drcv, char **astr)
{
	if ((drcv.oflags & PFO_X) && (drcv.oflags & PFO_ALT))
	{
		if (!is_zero(*astr))
		{
			if (drcv.oflags & PFO_CAPS)
				*astr = ft_strcfjoin("0X", astr);
			else
				*astr = ft_strcfjoin("0x", astr);
		}
	}
	else if (drcv.oflags & PFO_P)
		*astr = ft_strcfjoin("0x", astr);
	return (*astr);
}

/*
** o_prepend
** Entires an octal type ('o') begins with a zero.
*/

static char *o_prepend(t_pfdrcv drcv, char **astr)
{
	if (drcv.oflags & PFO_O)
		if (**astr != '0')
			*astr = ft_strcfjoin("0", astr);
	return (*astr);
}

char *pf_prec(t_pfdrcv drcv, char **astr)
{
	char *hold;

		if ((drcv.oflags & PFO_DIOUX) || (drcv.oflags & PFO_P))
		{
			if (drcv.oflags & PFO_PREC && (int)ft_strlen(*astr) < drcv.pv)
			{
				hold = gen_padding(drcv.pv - ft_strlen(*astr), '0');
				*astr = ft_strffjoin(&hold, astr);
			}
			if ((drcv.oflags & PFO_X) || (drcv.oflags & PFO_P))
				xp_prepend(drcv, astr);
			else if (drcv.oflags & PFO_O)
				o_prepend(drcv, astr);
		}
		else if ((drcv.oflags & PFO_PREC) && (drcv.oflags & PFO_S))
		{
			if ((drcv.oflags & PFO_L) && (int)ft_wstrlen((wchar_t *)*astr) > drcv.pv)
			{
				hold = *astr;
				*astr = (char *)ft_wstrsub((wchar_t *)hold, 0, drcv.pv);
				ft_memdel((void **)&hold);
			}
			if ((int)ft_strlen(*astr) > drcv.pv)
			{
				hold = *astr;
				*astr = ft_strsub(hold, 0, drcv.pv);
				ft_memdel((void **)&hold);
			}
		}
	return (*astr);
}