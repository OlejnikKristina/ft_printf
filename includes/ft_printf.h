/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:54:45 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/27 20:54:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ftpf_colors.h"
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>
# include "../includes/libft.h"
# include <limits.h>
# include <stdio.h>

# define COMPLITED 1
# define FINISHED 0
# define STAR -4242
# define DOT_ZERO -42
# define UNPR_NULL -2

typedef struct	s_format_spec
{
	long		width;
	long		precision;
	unsigned	dig_amount;
	bool		is_negative;
	bool		flag_minus;
	bool		flag_plus;
	bool		flag_space;
	bool		flag_zero;
	bool		flag_hash;
	bool		len_h;
	bool		len_hh;
	bool		len_l;
	bool		len_ll;
	bool		len_lupper;
	char		type;

}				t_format_spec;

typedef	struct	s_placeholder
{
	char		*str;
}				t_placeholder;

typedef	struct	s_output
{
	int			usage;
	char		*str;
}				t_output;

unsigned		count_digit64u(uint64_t nbr);
char			*itoa64u(uint64_t nbr);
unsigned		count_digit64(int64_t nbr);
char			*itoa64(int64_t nbr);
char			*itoa_base64(int64_t value, short base, bool uppercase);
char			*itoa_base64u(uint64_t value, short base, bool uppercase);
int				ft_printf(const char *format, ...);
char			*ft_superjoin(char **s1, const char *s2);
bool			copy_until(char *src, t_output *out, char percent);
void			move_ptr(char **input, char move_to, t_output *out);
bool			check_type(char **input, t_format_spec *format_specifier,
				bool feature);
bool			check_length_filed(char **input,
				t_format_spec *format_specifier);
bool			check_width_filed(char **input, t_format_spec *format_specifier,
				va_list arg_ptr);
bool			check_precision(char **input, t_format_spec *format_specifier,
				va_list arg_ptr);
bool			check_flags(char **input, t_format_spec *format_specifier);
void			integer(t_format_spec *specifier, t_placeholder *spec_res,
				va_list arg_ptr);
bool			int_width(t_format_spec *s, t_placeholder *result);
void			int_flag(t_format_spec *spec, t_placeholder *spec_res,
				char *num);
void			ft_ftoa(long double num, char **sfloat_str, unsigned precision,
				long double multiply_me);
void			int_flag_minus(t_format_spec *spec, t_placeholder *result);
void			int_precision(t_format_spec *spec, t_placeholder *result);
void			int_sign(t_format_spec *specifier, t_placeholder *spec_res);
void			add_zeros(unsigned dig_amount, char **result, ssize_t width);
int				type_c(t_format_spec *specifier, t_placeholder *result,
				va_list arg_ptr);
bool			type_s(t_format_spec *specifier, t_placeholder *result,
				va_list arg_ptr);
bool			type_p(t_format_spec *specifier, t_placeholder *result,
				va_list arg_ptr);
bool			type_f(t_format_spec *specifier, t_placeholder *result,
				va_list arg_ptr);
bool			type_percent(t_format_spec *s, t_placeholder *result,
				va_list arg_ptr);
bool			set_color(t_format_spec *specifier,
				t_placeholder *result, char **input);
#endif
