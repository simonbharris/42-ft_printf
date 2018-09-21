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

char *pf_di(t_pfdrcv drcv, va_list ap)
{
	intmax_t i;

	if (drcv.oflags & PFO_HH)
		i = (intmax_t)va_arg(ap, int);
	else if (drcv.oflags & PFO_H)
		i = (intmax_t)va_arg(ap, int);
	else if (drcv.oflags & PFO_L)
		i = (intmax_t)va_arg(ap, long);
	else if (drcv.oflags & PFO_LL)
		i = (intmax_t)va_arg(ap, long long);
	else if (drcv.oflags & PFO_J)
		i = (intmax_t)va_arg(ap, intmax_t);
	else if (drcv.oflags & PFO_Z)
		i = (intmax_t)va_arg(ap, size_t);
	else
		i = (intmax_t)va_arg(ap, int);
	return (ft_itoa(i));
}
