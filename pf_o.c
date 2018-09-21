/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:52:45 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 20:52:46 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *pf_o(t_pfdrcv drcv, va_list ap)
{
	size_t i;

	if (drcv.oflags & PFO_HH)
		i = (size_t)va_arg(ap, int);
	else if (drcv.oflags & PFO_H)
		i = (size_t)va_arg(ap, int);
	else if (drcv.oflags & PFO_L)
		i = (size_t)va_arg(ap, unsigned long);
	else if (drcv.oflags & PFO_LL)
		i = (size_t)va_arg(ap, unsigned long long);
	else if (drcv.oflags & PFO_J)
		i = (size_t)va_arg(ap, uintmax_t);
	else if (drcv.oflags & PFO_Z)
		i = (size_t)va_arg(ap, size_t);
	else
		i = (size_t)va_arg(ap, int);
	return(ft_itoabase(i, "01234567"));
}
