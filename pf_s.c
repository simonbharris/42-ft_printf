/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 06:33:50 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 06:34:19 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Obtains the parameter as a string or wide string.
*/

char	*pf_s(t_pfdrcv drcv, va_list ap)
{
	char	*str;
	wchar_t	*wstr;

	if (drcv.oflags & PFO_L)
	{
		if (NULL == (str = (char *)ft_wstrdup(va_arg(ap, wchar_t *))))
			return (NULL);
		wstr = (wchar_t *)str;
	}
	else
	{
		if (NULL == (str = ft_strdup((char *)va_arg(ap, char *))))
			return (NULL);
	}
	return (str);
}
