/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 06:37:02 by sharris           #+#    #+#             */
/*   Updated: 2018/09/17 06:37:14 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** CHK_SETO -- check and set options.
** Compares directive flags (dir) with supplied (opt) flag.
** if no match, check if our supplied dir char (dc) matches a flag char(fc)
** if match, bitwise or assignmento n the flag.
*/

#define CHK_SETO(d, o, c, f) !(d->oflags & o) && (f== c) && (d->oflags |= o);

/*
** skip_atoi
** leaps any digits in the string. Moves back 1 space so the guaranteed string
** increments in get_dir don't seg fault--In case the skip places us
** on a null-byte.
*/

static void		skip_atoi(const char **str)
{
	while (ft_isdigit(**str))
		*str += 1;
	*str -= 1;
}

/*
** initpfdir -- initialize a pfdir struct type.
** Initializes a pfdir struct, setting all values to defaults.
*/

static void		set_opt(t_pfdrcv *drcv, const char c)
{
	CHK_SETO(drcv, PFO_ALT, '#', c);
	CHK_SETO(drcv, PFO_SPC, ' ', c);
	CHK_SETO(drcv, PFO_LPD, '-', c);
	CHK_SETO(drcv, PFO_SIGN, '+', c);
	CHK_SETO(drcv, PFO_PAD0, '0', c);
}

static void		get_mfw_prec(t_pfdrcv *drcv, const char **format)
{
	if (**format == '.' && (drcv->oflags |= PFO_PREC)
	&& ((drcv->prec_val = ft_atoi((*format += 1))) || (**format == '0')))
		skip_atoi(format);
	else if (ft_isdigit(**format) && **format > '0')
		(drcv->mfw = ft_atoi(*format)) ? skip_atoi(format) : 0;
}

static void		get_lmod(t_pfdrcv *drcv, const char **format)
{
	if (IS_MOD(**format))
	{
		if ((ft_strnequ(*format, "hh", 2) && (drcv->oflags |= PFO_HH))
		|| (ft_strnequ(*format, "ll", 2) && (drcv->oflags |= PFO_LL)))
			*format += 1;
		else if (**format == 'h')
			drcv->oflags |= PFO_H;
		else if (**format == 'l')
			drcv->oflags |= PFO_L;
		else if (**format == 'j')
			drcv->oflags |= PFO_J;
		else if (**format == 'z')
			drcv->oflags |= PFO_Z;
	}
}

/*
** get_dir -- Get the directive.
** This functions parses the directive char '%'
** until a datatype character: sSpdDioOuUxXcC
** Stores the directive flags and values into a pfdir struct.
** Also advances the pointer to the format string the next
** non-option byte.
*/

t_pfdrcv		get_drcv(const char **format)
{
	t_pfdrcv drcv;

	drcv = initpfdir();
	while (**format && !ft_strchr("sSpdDioOuUxXcC", (int)**format))
	{
		set_opt(&drcv, **format);
		get_mfw_prec(&drcv, format);
		get_lmod(&drcv, format);
		*format += 1;
	}
	drcv.type = **format;
	*format += 1;
	return (drcv);
}
