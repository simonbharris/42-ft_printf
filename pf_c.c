/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:17:33 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 12:17:49 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *pf_c(t_pfdrcv drcv, va_list ap)
{
	char *str;
	wchar_t *ws;
	wchar_t wc;

	if (drcv.oflags & PFO_L)
	{
		MALCHECK(ws = ft_wstrnew(sizeof(wchar_t) * 2))
		wc = va_arg(ap, wchar_t);
		ws = ft_wstrdup(&wc);
		ws[1] = L'\x0';
		return ((char *)ws);
	}
	else
	{
		MALCHECK(str = ft_strnew(1))
		str[0] = va_arg(ap, int);
		return(str);
	}
}