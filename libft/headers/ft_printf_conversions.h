/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:33:33 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/06 22:12:23 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONVERSIONS_H
# define FT_PRINTF_CONVERSIONS_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define CONV_CHAR '%'
# define FLAGS "-0# +"
# define FLAG_COUNT 5
# define FI_DASH 0
# define FI_ZERO 1
# define FI_SHRP 2
# define FI_BLNK 3
# define FI_PLUS 4
# define PRECISION_FLAG '.'
# define LENGTH_FLAGS "lh"
# define CONV_SPECIFIERS "cspdiuoxX%nfge"
# define INT_GRP "di"
# define UINT_GRP "uoxX"
# define FLT_GRP "fge"

typedef struct	s_prf_traits
{
	char	flag[FLAG_COUNT];
	int		width;
	int		precision;
	char	length;
	char	conversion;
	int		flag_len;
	int		conv_len;
	int		ret_len;
}				t_prf_traits;

char			*format_string_handler(
		t_prf_traits *traits, const char *format, va_list ap);
char			*format_conversion_handler(
		t_prf_traits *traits, const char *format, va_list ap);
int				conversion_parse(
		t_prf_traits *traits, const char *format, va_list ap);
void			conversion_width_arrange(
		t_prf_traits *traits, char **str, int pad_len);
void			conversion_add_sign_int(
		t_prf_traits *traits, char **str, int neg_flag);
void			conversion_add_sign_uint(t_prf_traits *traits, char **str);
int				prefix_pad_char(
		char **str, char pad_char, int org_len, int pad_len);
int				prefix_str(char **str, char *pad_str, int org_len);
int				postfix_pad_char(
		char **str, char pad_char, int org_len, int pad_len);
char			*conversion_handler_c(t_prf_traits *traits, va_list ap);
char			*conversion_handler_s(t_prf_traits *traits, va_list ap);
char			*conversion_handler_n(t_prf_traits *traits, va_list ap);
char			*conversion_handler_p(t_prf_traits *traits, va_list ap);
char			*conversion_handler_int(t_prf_traits *traits, va_list ap);
char			*conversion_handler_uint(t_prf_traits *traits, va_list ap);
char			*conversion_handler_flt(t_prf_traits *traits, va_list ap);

#endif
