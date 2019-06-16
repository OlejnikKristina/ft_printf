/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:54:45 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/28 14:54:45 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>
# include "../includes/libft.h"

# include <limits.h>
# include <stdio.h>

# define COMPLITED 1
# define FINISHED 0
# define MIN_INT -2147483642
# define MAX_INT 2147483647

# define STAR -1

typedef struct	t_format_spec
{
	ssize_t		width;
	ssize_t		precision;
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
	bool		len_L;
	char		type;

}				s_format_spec;

typedef	struct	t_placeholder
{
	ssize_t		len;
	char		*str;
}				s_placeholder;


typedef	struct	t_output
{
	int			usage;
	int			size;
	char		*str;
}				s_output;


unsigned		count_digit64u(uint64_t nbr);
char			*itoa64u(uint64_t nbr);
unsigned		count_digit64(int64_t nbr);
char			*itoa64(int64_t nbr);
char			*itoa_base64(int64_t value, short base, bool uppercase);
char			*itoa_base64u(uint64_t value, short base, bool uppercase);

int				ft_printf(const char *format, ...);
char			*ft_superjoin(char **s1, const char *s2);
bool			copy_until(char *src, s_output *out, char percent);
void			move_ptr(char **input, char move_to, s_output *out);
bool			check_type(char **input, s_format_spec *format_specifier, bool feature);
bool			check_length_filed(char **input, s_format_spec *format_specifier);
bool			check_width_filed(char **input, s_format_spec *format_specifier);
bool			check_precision(char **input, s_format_spec *format_specifier);
bool			check_flags(char **input, s_format_spec *format_specifier);
bool			integer(s_format_spec *specifier, s_placeholder *spec_res, va_list arg_ptr);
void			int_flag(s_format_spec *spec, s_placeholder *spec_res);

void			int_flag_minus(s_format_spec *spec, s_placeholder *result);
void			int_sign(s_format_spec *specifier, s_placeholder *spec_res);
void			add_zeros(unsigned dig_amount, char **result, ssize_t width);
bool			type_c(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr);
bool			type_s(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr);
# endif