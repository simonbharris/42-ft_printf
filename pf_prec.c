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
     o   An optional precision, in the form of a period . followed by an optional digit string.  If the digit
         string is omitted, the precision is taken as zero.  This gives the minimum number of digits to appear
         for d, i, o, u, x, and X conversions, the number of digits to appear after the decimal-point for a, A,
         e, E, f, and F conversions, the maximum number of significant digits for g and G conversions, or the
         maximum number of characters to be printed from a string for s conversions.
*/

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

// ! Non-numeric datatypes not yet supported.
char *pf_prec(t_pfdrcv drcv, char **astr)
{
	char *zero;

		if ((drcv.oflags & PFO_DIOUX) || (drcv.oflags & PFO_P))
		{
			if (drcv.oflags & PFO_PREC && ft_strlen(*astr) < drcv.pv)
			{
				zero = gen_padding(drcv.pv - ft_strlen(*astr), '0');
				*astr = ft_strffjoin(&zero, astr);
			}
			if ((drcv.oflags & PFO_X) || (drcv.oflags & PFO_P))
				xp_prepend(drcv, astr);
			else if (drcv.oflags & PFO_O)
				o_prepend(drcv, astr);
		}
	return (*astr);
}