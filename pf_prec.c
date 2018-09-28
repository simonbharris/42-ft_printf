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

static int	is_hexzero(char *str)
{
	while (*str)
		if (*str++ != '0')
			return (0);
	return (1);
}

/*
** pf_prec_n Precision numeric
** Pads with zeros up to length of precision.
** if alt flag is enabled or is a pointer type, prepends 0, 0x, or 0X
** to the appropriate types.
** (Handles diouxbp types, with special cases for oxp)
*/

static void	pf_prec_n(t_pfdrcv drcv, char **astr, char **hold)
{
	if (drcv.oflags & PFO_PREC && (int)ft_strlen(*astr) < drcv.pv)
	{
		*hold = gen_padding(drcv.pv - ft_strlen(*astr), '0');
		*astr = ft_strffjoin(hold, astr);
	}
	if ((drcv.oflags & PFO_X) && (drcv.oflags & PFO_ALT))
	{
		if (!is_hexzero(*astr))
		{
			if (drcv.oflags & PFO_CAPS)
				*astr = ft_strcfjoin("0X", astr);
			else
				*astr = ft_strcfjoin("0x", astr);
		}
	}
	else if (drcv.oflags & PFO_P)
		*astr = ft_strcfjoin("0x", astr);
	else if (drcv.oflags & PFO_B)
		*astr = ft_strcfjoin("0b", astr);
	else if (drcv.oflags & PFO_O && drcv.oflags & PFO_ALT)
		if (**astr != '0')
			*astr = ft_strcfjoin("0", astr);
}

/*
** pf_prec_s string precision
** Truncates the string so that it is no longer
** than the precision value (drcv.pv)
*/

static void	pf_prec_s(t_pfdrcv drcv, char **astr, char **hold)
{
	if ((drcv.oflags & PFO_L) && (int)ft_wstrlen((wchar_t *)*astr) > drcv.pv)
	{
		*hold = *astr;
		*astr = (char *)ft_wstrsub((wchar_t *)*hold, 0, drcv.pv);
		ft_memdel((void **)hold);
	}
	if ((int)ft_strlen(*astr) > drcv.pv)
	{
		*hold = *astr;
		*astr = ft_strsub(*hold, 0, drcv.pv);
		ft_memdel((void **)hold);
	}
}

/*
** pf_prec - pf precision
** Directs to either numeric precision, or string precision functions.
*/

char		*pf_prec(t_pfdrcv drcv, char **astr)
{
	char *hold;

	if ((drcv.oflags & (PFO_DIOUXB | PFO_P)))
		pf_prec_n(drcv, astr, &hold);
	else if ((drcv.oflags & PFO_PREC) && (drcv.oflags & PFO_S))
		pf_prec_s(drcv, astr, &hold);
	return (*astr);
}
