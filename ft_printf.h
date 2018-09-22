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
# define PF_DFLAG "sSpdDioOuUxXcC"
# define IS_MOD(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')
# define IS_2CHARMOD(x) ((x)[1] == 'h' || (x)[1] == 'l')

/*
** Option Flag tabke for ft_printf
** 0000xx == options and precision flags
** 00xx00 == length modifier flags
** xx0000 == type modifier flags
*/

#define PFO_ALT		0x000001
#define PFO_PAD0	0x000002
#define PFO_SPC		0x000004
#define PFO_LPD		0x000008

#define PFO_SIGN	0x000010
#define PFO_PREC	0x000020

#define PFO_2MOD	0x000100
#define PFO_H		0x000200
#define PFO_L		0x000400
#define PFO_J		0x000800
#define PFO_Z		0x001000
#define PFO_CAPS	0x002000

#define PFO_S		0x010000
#define PFO_P		0x020000
#define PFO_D		0x040000
#define PFO_I		0x080000
#define PFO_O		0x100000
#define PFO_U		0x200000
#define PFO_X		0x400000
#define PFO_C		0x800000

/*
** Compound flags
*/

#define PFO_HH		0x000300
#define PFO_LL		0x000500
#define PFO_DIOUX	0x7c0000

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
}				t_pfdrcv;

int			ft_printf(const char *format, ...);

void		skip_atoi(const char **str);
t_pfdrcv	get_drcv(const char **format);
t_pfdrcv	initpfdir(void);
int			put_drcv(t_pfdrcv drcv, va_list ap);

char 		*pf_di(t_pfdrcv drcv, va_list ap);
char		*pf_o(t_pfdrcv drcv, va_list ap);
char		*pf_u(t_pfdrcv drcv, va_list ap);


#endif
