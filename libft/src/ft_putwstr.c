/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:53:33 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 10:55:23 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Put wide string
** Writes to stdout an array of wchar_t
*/

void	ft_putwstr(wchar_t *wstr)
{
	int i;
	int j;
	int numb;
	unsigned char *byte;
	
	i = 0;
	numb = 0;
	while (wstr[i])
	{
		j = 0;
		byte = (unsigned char *)wstr;
		while (j++ < 4)
		{
			if (*byte++)
				numb = j;
		}
		write(1, wstr, numb);
		wstr++;
		i++;
	}
}
