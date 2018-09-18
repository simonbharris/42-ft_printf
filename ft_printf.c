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

#define CHK_SETO(dir, opt, fc, dc) !(dir & opt) && (dc == fc) && (dir |= opt);

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

static t_pfdir	initpfdir(void)
{
	t_pfdir dir;

	dir.oflags = 0;
	dir.mfw = 0;
	ft_bzero(dir.mod, sizeof(char) * 3);
	dir.type = '\0';
	return (dir);
}

/*
** get_dir -- Get the directive.
** This functions parses the directive char '%'
** until a datatype character: sSpdDioOuUxXcC
** Stores the directive flags and values into a pfdir struct.
** Also advances the pointer to the format string the next
** non-option byte.
*/

t_pfdir			get_dir(const char **format)
{
	t_pfdir dir;

	dir = initpfdir();
	while (**format && !(IS_TYPE(**format)))
	{
		CHK_SETO(dir.oflags, PFO_ALT, '#', **format);
		CHK_SETO(dir.oflags, PFO_SPC, ' ', **format);
		CHK_SETO(dir.oflags, PFO_LPD, '-', **format);
		CHK_SETO(dir.oflags, PFO_SIGN, '+', **format);
		if (**format == '.' && (dir.oflags |= PFO_PREC)
		&& ((dir.prec_val = ft_atoi((*format += 1))) || (**format == '0')))
			skip_atoi(format);
		else if (ft_isdigit(**format) && **format > '0')
			(dir.mfw = ft_atoi(*format)) ? skip_atoi(format) : 0;
		else if (**format == '0')
			dir.oflags |= PFO_PAD0;
		if (!dir.mod[0] && IS_MOD(**format) && (dir.mod[0] = **format))
			dir.mod[1] = (IS_2CHARMOD(*format)) ? (*format)[1] : 0;
		*format += 1;
	}
	dir.type = **format;
	*format += 1;
	return (dir);
}

// int			ft_printf(const char *format, ...)
// {
// 	va_list ap;
// 	t_pfdir dir;

// 	va_start(ap, format);
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			if (format[1] == '%')
// 			{
// 				ft_putchar('%');
// 				format += 2;
// 				continue ;
// 			}
// 			dir = get_dir(&format);
// 		}
// 	}
// 	return(0);
// }

/*
static void	putformat(const char *format, va_list ap)
{
	// Escape char
	if (*format == '%')
		ft_putchar('%');

	// Options	
	// - Alternate
	if (*format == '#')
		pf_alt(*format, ap);
		
	// Padding [space], zero, and mfw (minimum field width)
	if (*format == ' ')
		pf_padspace(*format, ap);
	if (ft_isdigit((int) *format))
		pf_mfw(*format, ap);
	if (IS_SIGN(*format))
		pf_sign(*format, ap);
	if (*format == '.')
		pf_prec(*format, ap);


	// Types
	if (*format == 's')
		ft_putstr(va_arg(ap, char));
	if (*format == 'S')
		ft_putwstr(va_arg(ap, wchar_t));
	if (*format == 'p')
		ft_putadr(va_arg(ap, void *));
	if (*format == 'D')
		ft_putD(va_arg(ap, long int));
	if (*format == 'd' || *format == 'i')
		ft_putd(va_arg(ap, int));
	if (*format == 'o')
		ft_putuoct(va_arg(ap, int));
	if (*format == 'O')
		ft_putUoct(va_arg(ap, long int));
	if (*format == 'u')
		ft_putudec(va_arg(ap, int));
	if (*format == 'U')
		ft_putUdec(va_arg(ap, long int));
	if (*format == 'x')
		ft_puthex(va_arg(ap, int));
	if (*format == 'X')
		ft_putuhex(va_arg(ap, int));
	if (*format == 'c')
		ft_putitouc(va_arg(ap, int));
	if (*format == 'C')
		ft_putwitowc(va_arg(ap, wint_t));
// 17 - 41 + 1 = 25 lines
}
*/