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
# include <stdio.h>
# define COMPLITED 1
# define FINISHED 0
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define STAR -1

typedef struct	t_format_spec
{
	char		type;
	bool		flag_minus;
	bool		flag_plus;
	bool		flag_space;
	bool		flag_zero;
	bool		flag_hash;
	ssize_t		width;
	ssize_t		precision;
	bool		len_h;
	bool		len_hh;
	bool		len_l;
	bool		len_ll;
	bool		len_L;

}				s_format_spec;

typedef	struct	t_placeholder
{
	char		*str;
	ssize_t		len;
}				s_placeholder;


typedef	struct	t_output
{
	char		*str;
	int			usage;
	int			size;
}				s_output;


int				ft_printf(const char *format, ...);
char			*ft_superjoin(char **s1, const char *s2);
bool			copy_until(char *src, s_output *out, char percent);
void			move_ptr(char **input, char move_to, s_output *out);
bool			check_type(char **input, s_format_spec *format_specifier);
bool			check_length_filed(char **input, s_format_spec *format_specifier);
bool			check_width_filed(char **input, s_format_spec *format_specifier);
bool			check_precision(char **input, s_format_spec *format_specifier);
bool			check_flags(char **input, s_format_spec *format_specifier);
bool			type_d(s_format_spec *specifier, s_placeholder *spec_res, va_list arg_ptr);
# endif