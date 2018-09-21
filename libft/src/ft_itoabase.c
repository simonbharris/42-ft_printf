/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:23:28 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 19:23:31 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_allocsize(int nbr, int base)
{
	int i;

	i = 1;
	if (nbr == 0)
		return (i);
	while ((nbr /= 10) > 0)
		i++;
	return (i);
}

char		*ft_itoabase(size_t nbr, char *base)
{
	char	*str;
	int		blen;
	int		len;

	blen = ft_strlen(base);
	if (blen < 2)
		return (NULL);
	len = get_allocsize(nbr, blen);
	str = ft_strnew((size_t)len);
	if (nbr == 0)
	{
		*str = '0';
		return (str);
	}
	while (nbr > 0)
	{
		str[--len] = *((nbr % ft_strlen(base) + base));
		nbr /= ft_strlen(base);
	}
	return (str);
}
