/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 07:40:06 by sharris           #+#    #+#             */
/*   Updated: 2018/09/23 07:40:48 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *pf_p(t_pfdrcv drcv, va_list ap)
{
	size_t i;
	
	if (sizeof(void *) == 8)
		i = va_arg(ap, unsigned long);
	else
		i = va_arg(ap, unsigned int);
	return (ft_itoabase(i, "0123456789abcdef"));
}
