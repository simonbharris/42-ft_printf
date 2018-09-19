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

# define IS_MOD(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')
# define IS_2CHARMOD(x) ((x)[1] == 'h' || (x)[1] == 'l')

/*
** Option Flag tabke for ft_printf
** 00xx == options and precision flags
** xx00 == length modifier flags
*/
#define PFO_ALT		0x0001
#define PFO_PAD0	0x0002
#define PFO_SPC		0x0004
#define PFO_LPD		0x0008
#define PFO_SIGN	0x0010
#define PFO_PREC	0x0020

#define PFO_2MOD	0x0100
#define PFO_H		0x0200
#define PFO_L		0x0400
#define PFO_J		0x0800
#define PFO_Z		0x1000

/*
** Compound flags
*/
#define PFO_HH		0x0300
#define PFO_LL		0x0500

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

typedef struct	s_pfdrcv
{
	int		oflags;
	int		prec_val;
	int		mfw;
	char	type;
}				t_pfdrcv;

t_pfdrcv	get_drcv(const char **format);
t_pfdrcv	initpfdir(void);

#endif
