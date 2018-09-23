/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:22:31 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 20:22:32 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static char *prepend_str(intmax_t i, const char *str)
// {
// 	char *chr;
// 	char *ret;

// 	chr = ft_strdup(str);
// 	ret = ft_itoa(i);
// 	return (ft_strffjoin(&chr, &ret));
// }

char *pf_di(t_pfdrcv drcv, va_list ap)
{
	intmax_t i;

	if (drcv.oflags & PFO_HH)
		i = va_arg(ap, int);
	else if (drcv.oflags & PFO_H)
		i = va_arg(ap, int);
	else if (drcv.oflags & PFO_L)
		i = va_arg(ap, long);
	else if (drcv.oflags & PFO_LL)
		i = va_arg(ap, long long);
	else if (drcv.oflags & PFO_J)
		i = va_arg(ap, intmax_t);
	else if (drcv.oflags & PFO_Z)
		i = va_arg(ap, size_t);
	else
		i = va_arg(ap, int);
	return (ft_itoa(i));
}
