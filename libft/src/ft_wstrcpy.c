/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:31:45 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 12:32:01 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Wide string copy
** Swites the contents of a null-terminated src to dst.
** dst must have room otherwise results are undefined.
*/

wchar_t	*ft_wstrcpy(wchar_t *dst, const wchar_t *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = L'\0';
	return (dst);
}
