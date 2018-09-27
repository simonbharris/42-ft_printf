/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:58:52 by sharris           #+#    #+#             */
/*   Updated: 2018/07/09 20:58:52 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_alloc_size(long long nbr)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= 10;
	}
	if (nbr < 0)
		return (i + 2);
	return (i + 1);
}

static long long	check_neg_make_abs(long long *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	else
		return (0);
}

char		*ft_lltoa(long long n)
{
	char			*str;
	long long		i;

	i = 0;
	if (NULL == (str = ft_memalloc(get_alloc_size(n))))
		return (NULL);
	if (n == -9223372036854775807)
		ft_strcpy(&(*str), "-9223372036854775808");
	else
	{
		i = get_alloc_size(n) - 1;
		if (n == 0)
			str[0] = '0';
		else
		{
			if (check_neg_make_abs(&n))
				str[0] = '-';
			while (n > 0)
			{
				str[--i] = ((n % 10) + '0');
				n /= 10;
			}
		}
	}
	return (str);
}
