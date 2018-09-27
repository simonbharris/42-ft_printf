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
** skip_atoi
** leaps any digits in the string. Moves back 1 space so the guaranteed string
** increments in get_drcv don't seg fault--In case the skip places us
** on a null-byte.
*/

/*
** Details for the following 3 funcitons:
** set_opt = set options
** set_mfw_prec = sets the precision and mfw flags and also obtains
**		the minium field width and precision values.
** set_lmod = get length modifier
** set_type
** all 3 functions add flags to drcv.oflags depending on what they find.
*/

static void		set_opt(t_pfdrcv *drcv, const char c)
{
	if(!(drcv->oflags & PFO_ALT) && (c == '#'))
		drcv->oflags |= PFO_ALT;
	if(!(drcv->oflags & PFO_PAD0) && (c == '0'))
		drcv->oflags |= PFO_PAD0;
	if(!(drcv->oflags & PFO_SPC) && (c == ' '))
		drcv->oflags |= PFO_SPC;
	if(!(drcv->oflags & PFO_LPD) && (c == '-'))
		drcv->oflags |= PFO_LPD;
	if(!(drcv->oflags & PFO_SIGN) && (c == '+'))
		drcv->oflags |= PFO_SIGN;
}

static void		set_mfw_prec(t_pfdrcv *drcv, const char **format)
{
	if (**format == '.' || ft_isdigit(**format))
	{
		if (**format == '.')
		{
			drcv->oflags |= PFO_PREC;
			if (ft_isdigit((*format)[1]))
				drcv->pv = ft_atoi((*format += 1));
		}
		else
			drcv->mfw = ft_atoi(*format);
		if (**format == '-' || ft_isdigit(**format))
			skip_atoi(format);
	}
}

static void		set_lmod(t_pfdrcv *drcv, const char **format)
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

static void		set_type(t_pfdrcv *drcv, const char **format)
{
	if (ft_strchr("DOUSC", (int)**format))
		drcv->oflags |= PFO_L;
	if (ft_tolower((int)**format) == 'd')
		drcv->oflags |= PFO_D;
	else if (ft_tolower((int)**format) == 'o')
		drcv->oflags |= PFO_O;
	else if (ft_tolower((int)**format) == 'u')
		drcv->oflags |= PFO_U;
	else if (ft_tolower((int)**format) == 's')
		drcv->oflags |= PFO_S;
	else if (ft_tolower((int)**format) == 'c')
		drcv->oflags |= PFO_C;
	else if (ft_tolower((int)**format) == 'p')
		drcv->oflags |= PFO_P;
	else if (ft_tolower((int)**format) == 'i')
		drcv->oflags |= PFO_I;
	else if (**format == 'b')
		drcv->oflags |= PFO_B;
	else if (ft_tolower((int)**format) == 'x')
	{
		if (**format == 'X')
			drcv->oflags |= PFO_CAPS;
		drcv->oflags |= PFO_X;
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

t_pfdrcv		get_drcv(const char *format)
{
	t_pfdrcv drcv;

	drcv = initpfdir();
	while (*format && !ft_strchr("sSpdDioOuUxXcCb", (int)*format))
	{
		set_opt(&drcv, *format);
		set_mfw_prec(&drcv, &format);
		set_lmod(&drcv, &format);
		format += 1;
	}
	set_type(&drcv, &format);
	format += 1;
	return (drcv);
}
