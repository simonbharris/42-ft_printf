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
** increments in get_dir don't seg fault--In case the skip places us
** on a null-byte.
*/

static void	skip_atoi(const char **str)
{
	while (ft_isdigit(**str))
		*str += 1;
	*str -= 1;
}

static t_pfdir	initpfdir(void)
{
	t_pfdir dir;

	dir.alt = 0;
	dir.padzero = 0;
	dir.space = 0;
	dir.mfw = 0;
	dir.lpad = 0;
	dir.sign = 0;
	ft_bzero(dir.mod, sizeof(char) * 3);
	char type = '\0';
	return (dir);
}

t_pfdir	get_dir(const char **format)
{
	t_pfdir dir;

	dir = initpfdir();
	while (**format && !(IS_TYPE(**format)))
	{
		!dir.alt && (dir.alt = **format == '#');
		!dir.padzero && (dir.padzero = **format == '0');
		!dir.space && (dir.space = **format == ' ');
		!dir.lpad && (dir.lpad = **format == '-');
		!dir.sign && (dir.sign = **format == '+');
		if (ft_isdigit(**format) && !(dir.padzero = (!ft_atoi(*format))))
		{
			dir.mfw = ft_atoi(*format);
			skip_atoi(format);
		}
		if (IS_MOD(**format) && (dir.mod[0] = **format))
			dir.mod[1] = IS_2CHARMOD(*format) && *(*format += 1) ? (*format)[0] : 0;
		*format += 1;
	}
	dir.type = **format;
	return (dir);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_pfdir dir;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (format[1] == '%')
			{
				ft_putchar('%');
				format += 2;
				continue ;
			}
			dir = get_dir(&format);
		}
	}
	return(0);
}

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