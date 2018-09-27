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


// TODO: 
// MFW (Minimum field width value aka right-aligned padding)
// ' ' (Pad with space if numeric positive)
// '+' (Explicit sign for numeric types)
// '-' (Left-aligned padding)

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
				format += 1;
			}
			else
			{
				drcv = get_drcv(format);
				while (!ft_strchr("sSpdDioOuUxXcCb", *format++));
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
