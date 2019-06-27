/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_format_specifier.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 00:12:30 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/27 18:49:32 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	check_flags(char **input, s_format_spec *specifier)
{
	while (ft_strchr("-+ 0#", **input))
	{
		if (**input == '-')
			(specifier->flag_minus = true);
		if (**input == '+')
			(specifier->flag_plus = true);
		if (**input == ' ')
			(specifier->flag_space = true);
		if (**input == '0')
			(specifier->flag_zero = true);
		if (**input == '#')
			(specifier->flag_hash = true);
		(*input)++;
	}
	return (true);
}

bool	check_precision(char **input, s_format_spec *specifier, va_list arg_ptr)
{
	specifier->precision = 0;
	if ((*input)[0] == '.')
		(*input)++;
	else
		return (false);
	if (**input == '*')
	{
		specifier->precision = -4242;
		(*input)++;
	}
	else if (ft_isdigit(**input))
	{
		specifier->precision = ft_atoi(*input);
		(*input) += ft_count_digit(specifier->precision);
	}
	return (true);
}

bool	check_width_filed(char **input, s_format_spec *format_specifier,
va_list arg_ptr)
{
	format_specifier->width = 0;
	if (**input == '*')
	{
		format_specifier->width = (int)va_arg(arg_ptr, int);
		if (format_specifier->width < 0)
		{
			format_specifier->width *= -1;
			format_specifier->flag_minus = true;
		}
		(*input)++;
	}
	else if (ft_isdigit(**input))
	{
		format_specifier->width = ft_atoi(*input);
		(*input) += ft_count_digit(format_specifier->width);
	}
	else if(!ft_strcmp(*input, "RED"))
	{
		format_specifier->color = ft_strdup("\033[1;31m");
		(*input) += 3;
	}
	return (format_specifier->width);
}

bool	check_length_filed(char **input, s_format_spec *format_specifier)
{
	if (**input == 'h' && (*input)[1] == 'h')
		format_specifier->len_hh = true;
	else if (**input == 'h')
		format_specifier->len_h = true;
	else if (**input == 'l' && (*input)[1] == 'l')
		format_specifier->len_ll = true;
	else if (**input == 'l')
		format_specifier->len_l = true;
	else if (**input == 'L')
		format_specifier->len_L = true;
	else
		return (false);
	if (format_specifier->len_hh || format_specifier->len_ll)
		(*input)++;
	(*input)++;
	return (true);
}

bool	check_type(char **input, s_format_spec *specifier, bool no_dot)
{
	if (ft_strchr("%cspdiouxXf{", **input))
	{
		specifier->type = **input;
		(*input)++;
		if (no_dot && ft_strchr("sidouxXpCS", specifier->type)
		&& specifier->precision == 0)
			specifier->precision = DOT_ZERO;
		if (!no_dot && specifier->type == 'f' && specifier->precision == 0)
			specifier->precision = 6;
		if (specifier->type == 'C')
			specifier->type = 'c';
		if (specifier->type == 'S')
			specifier->type = 'c';
	}
	else
		return (false);
	return (true);
}
