/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:50 by yoribeir          #+#    #+#             */
/*   Updated: 2019/04/11 21:06:35 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

# define LEFT_ALIGN	(1 << 0)
# define SPACE		(1 << 1)
# define PLUS		(1 << 2)
# define ZERO_FILL	(1 << 3)
# define PREFIX		(1 << 4)

# define NONE			(1 << 5)
# define FLAGS_HH		(1 << 6)
# define FLAGS_H		(1 << 7)
# define FLAGS_L		(1 << 8)
# define FLAGS_LL		(1 << 9)
# define FLAGS_J		(1 << 10)
# define FLAGS_Z		(1 << 11)

# define NEG			(1 << 12)
# define CAPSBASE		(1 << 13)
# define UNSIGNED		(1 << 14)
# define PRECISION		(1 << 15)
# define ZEROVALUE		(1 << 16)
# define UMAJ			(1 << 17)
# define ZEROPREC		(1 << 18)

# define BUF_SIZE 128

typedef	struct	s_parser
{
	int			width;
	int			precision;
	int			len;
	int			slen;
	int			base;
	long		f;
	char		*s;
	char		*prefix;
	char		format;
	char		*buf;
}				t_parser;

typedef	int	(*t_jumptable)(t_parser *p, va_list args);
int				ft_printf(const char *format, ...);

/*
** -------- PARSERS --------
*/

int				parse_flags(t_parser *p, char **format);
int				parse_width(t_parser *p, char **format);
int				parse_precision(t_parser *p, char **format);
void			parse_length(t_parser *p, char **format);
char			*get_prefix(t_parser *p, char c);

/*
** -------- HANDLERS --------
*/

t_jumptable		init_table(char c);
intmax_t		get_int_length(t_parser *p, va_list args);
int				handle_int(t_parser *p, va_list args);
int				handle_unsigned(t_parser *p, va_list args);
int				handle_octal(t_parser *p, va_list args);
int				handle_char(t_parser *p, va_list args);
int				handle_pointer(t_parser *p, va_list args);
int				handle_escape(t_parser *p, va_list args);
int				handle_string(t_parser *p, va_list args);
int				handle_wchar(t_parser *p, va_list args);
int				handle_wstring(t_parser *p, va_list args);
int				handle_float(t_parser *p, va_list args);

void			print_buffer(char *buf, int len, int *ret);
void			print_width(t_parser *p, int len, int *ret, int flag);
void			print_strwidth(t_parser *p, int len, int *ret);
void			handle_uprec(t_parser *p, char *buf, int *len);
void			append_uprefix(t_parser *p, char *buf, int *len);

/*
** UTILS
*/

char			*itoa_base_long(t_parser *p, long long n, int base, char *s);
void			itoa_handlezero(t_parser *p, intmax_t nbr);
char			*itoa_base_ulong(t_parser *p, uintmax_t n, int base, char *s);
int				get_base(t_parser *p, char c);
void			ft_putwchar(wchar_t chr);

#endif
