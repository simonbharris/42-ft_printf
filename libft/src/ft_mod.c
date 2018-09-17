/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:29:03 by sharris           #+#    #+#             */
/*   Updated: 2018/07/27 20:29:03 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_mod(int nbr, int mod)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < nbr)
	{
		n = n + 1 == mod ? 0 : n + 1;
		i++;
	}
	return (n);
}
