/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:57:14 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 15:57:15 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* NOTHING HERE WORKS / TRASH CODE! */
int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_pfdrcv drcv;
	int numwrite;

	numwrite = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (format[1] == '%')
			{
				ft_putchar('%');
				format += 2;
			}
			else
			{
				drcv = get_drcv(&format);
				numwrite += put_drcv(drcv, ap);
				continue ;
			}
		}
		else
			ft_putchar(*format);
		numwrite++;
		format++;
	}
	return(numwrite);
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
