/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 06:50:18 by sharris           #+#    #+#             */
/*   Updated: 2018/09/17 07:08:21 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <locale.h>
# include <stdarg.h>
# include <libft.h>

# define TRUE 1
# define FALSE 0
# define IS_SIGN(x) x == '+' || x == '-'

/*
** ft_printf types and modifiers
*/
# define IS_SPD(x) (x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D')
# define IS_IOU(x) (x == 'i' || x == 'o' || x == 'O' || x == 'u' || x == 'U')
# define IS_XC(x) (x == 'x' || x == 'X' || x == 'c' || x == 'C')
# define IS_TYPE(x) IS_SPD(x) || IS_IOU(x) || IS_XC(x)

# define IS_MOD(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')
# define IS_2CHARMOD(x) ((x)[1] == 'h' || (x)[1] == 'l')

/*
** s_pfdir (aka struct printf_directive)
** alt == '#' flag
** padzero == bool; pad with zero?
** space == boo; space before positive number?
** mfw == minimum field width, for padding.
** lpad == bool; left pad?
** sign == bool; explicitly print positive sign? ('+')
** mod == hh, h, l, ll, j, et, z (mod[0] != 0 if value exists)
** type == one of: sSpdDioOuUxXcC
*/

typedef struct	s_pfdir
{
	int		alt;
	int		padzero;
	int		space;
	int		mfw; 
	int		lpad;
	int		sign;
	int		prec;
	char	mod[3];
	char	type;
}				t_pfdir;

t_pfdir	get_dir(const char **format);

#endif
