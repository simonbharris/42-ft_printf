/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdrcv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:00:45 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 16:00:46 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	? Modifier          d, i           o, u, x, X
	  hh                signed char    unsigned char
	* h                 short          unsigned short
	  l (ell)           long           unsigned long
	* ll (ell ell)      long long      unsigned long long
	  j                 intmax_t       uintmax_t
	* z                 (see note)     size_t
*/

// * # define PF_DFLAG "sSpdDioOuUxXcC"

char *pf_dioux(t_pfdrcv drcv, va_list ap)
{
	if (drcv.oflags & PFO_D || drcv.oflags & PFO_I)
		return (pf_di(drcv, ap));
	else if (drcv.oflags & PFO_O)
		return (pf_o(drcv, ap));
	else if (drcv.oflags & PFO_U)
		return (pf_u(drcv, ap));
	// else if (drcv.oflags & PFO_X)
	// 	return (pf_x(drcv, ap));
	return (NULL);
}

char *dispatcher(t_pfdrcv drcv, va_list ap)
{
	if (drcv.oflags & PFO_DIOUX)
		return (pf_dioux(drcv, ap));
	// else if (drcv.type == 's')
	// 	pf_s(drcv, ap);
	// else if (drcv.type == 'p')
	// 	pf_p(drcv, ap);
	// else if (drcv.type == 'c')
	// 	pf_c(drcv, ap);
	return (NULL);
}

int		put_drcv(t_pfdrcv drcv, va_list ap)
{
	char *str;
	int len;
	
	str = dispatcher(drcv, ap);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

