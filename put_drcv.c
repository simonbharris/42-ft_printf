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
	else if (drcv.oflags & PFO_X)
		return (pf_x(drcv, ap));
	return (NULL);
}

char *dispatcher(t_pfdrcv drcv, va_list ap)
{
	if (drcv.oflags & PFO_DIOUX)
		return (pf_dioux(drcv, ap));
	else if (drcv.oflags & PFO_S)
		return (pf_s(drcv, ap));
	else if (drcv.oflags & PFO_P)
		return (pf_p(drcv, ap));
	else if (drcv.oflags & PFO_C)
		return (pf_c(drcv, ap));
	return (NULL);
}

int		put_drcv(t_pfdrcv drcv, va_list ap)
{
	char *str;
	int len;

	if ((str = dispatcher(drcv, ap)) == NULL)
		return (0);
	if (drcv.oflags & PFO_ALT || drcv.oflags & PFO_PREC || drcv.oflags & PFO_P)
		pf_prec(drcv, &str);
	else if (drcv.oflags & PFO_PAD0 && !(drcv.oflags & PFO_LPD))
		pf_zero(drcv, &str);
	if (drcv.oflags & PFO_SIGN)
		pf_sign(drcv, &str);
	if (drcv.oflags & PFO_LPD && drcv.mfw > (int)ft_strlen(str))
		pf_lpad(drcv, &str);
	else if (drcv.mfw > (int)ft_strlen(str))
		pf_pad(drcv, &str);
	else if (drcv.oflags & PFO_SPC)
		pf_space(drcv, &str);
	if ((drcv.oflags & PFO_SC) && (drcv.oflags & PFO_L))
		ft_putwstr((wchar_t *)str);
	else
		ft_putstr(str);
	len = ft_strlen(str);
	ft_memdel((void **)&str);
	return (len);
}
