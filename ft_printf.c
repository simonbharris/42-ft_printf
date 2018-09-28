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

static int	putfmt(const char **afmt, va_list ap, int *numwrite)
{
	t_pfdrcv drcv;

	if ((*afmt)[1] == '%')
	{
		ft_putchar('%');
		*afmt += 1;
		return (0);
	}
	else
	{
		drcv = get_drcv(*afmt);
		while (!ft_strchr("sSpdDioOuUxXcCb", **afmt))
			*afmt += 1;
		*afmt += 1;
		numwrite += put_drcv(drcv, ap);
		return (1);
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		numwrite;

	numwrite = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (putfmt(&format, ap, &numwrite))
				continue ;
		}
		else
			ft_putchar(*format);
		numwrite++;
		format++;
	}
	return (numwrite);
}
