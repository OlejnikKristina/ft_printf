/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_f.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/21 15:26:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_flag_zero(s_format_spec *spec,
s_placeholder *result, unsigned len)
{
	char		*zero_str;
	char		*holder;

	if (spec->is_negative || spec->flag_plus)
		len++;
	holder = result->str;
	zero_str = ft_strnew(len);
	ft_memset((void *)zero_str, '0', len);
	if (spec->is_negative || spec->flag_plus || spec->flag_space)
	{
		(spec->flag_plus) ? zero_str[0] = '+' : 1;
		(spec->is_negative) ? zero_str[0] = '-' : 1;
		(spec->flag_space) ? zero_str[0] = ' ' : 1;
	}
	if (spec->is_negative || spec->flag_plus)
		result->str = ft_superjoin(&zero_str, &result->str[1]);
	else
		result->str = ft_superjoin(&zero_str, result->str);
	ft_strdel(&zero_str);
	ft_strdel(&holder);
}

void	f_width(s_format_spec *spec, s_placeholder *result)
{
	char	*holder;
	char	*fill_width;
	int		len;

	holder = result->str;
	len = spec->width - ft_strlen(result->str);
	if (len <= 0)
		return ;
	if (spec->flag_zero && !spec->flag_minus)
	{
		f_flag_zero(spec, result, len);
		return ;
	}
	fill_width = ft_strnew(len + 1);
	ft_memset((void *)fill_width, ' ', len);
	if (spec->flag_minus)
		result->str = ft_superjoin(&result->str, fill_width);
	else
	{
		result->str = ft_superjoin(&fill_width, result->str);
		ft_strdel(&holder);
	}
	ft_strdel(&fill_width);
}

void	f_precision(s_format_spec *specifier, s_placeholder *result, char **fill_precision)
{
	*fill_precision = NULL;
	if (18 < specifier->precision)
	{
		*fill_precision = ft_strnew(specifier->precision - 18);
		ft_memset(*fill_precision, '0', specifier->precision - 18);
		specifier->precision = 18;
	}
}

void	f_flags(s_format_spec *spec, s_placeholder *result, char *holder)
{
	if (spec->flag_plus && !spec->is_negative)
	{
		result->str = ft_strjoin("+", holder);
	}
	else if (spec->flag_space && (!spec->flag_zero || spec->flag_minus))
		result->str = ft_strjoin(" ", holder);
	else if (!result->str)
		result->str = ft_strdup(holder);
}

void	f_check_exeption(s_format_spec *specifier, s_placeholder *result, long double *value)
{
	long double num;

	if (*value == 0.0)
	{
		num = 1 / *value;
		if (num < 0)
		{
			ft_strdel(&result->str);
			result->str = ft_strdup("-0.0");
		}
	}
}

bool	type_f(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	long double	value;
	char		*holder;
	char		*fill_precision;

	if (specifier->width == STAR)
		specifier->width = va_arg(arg_ptr, long);
	if (specifier->precision == STAR)
		specifier->precision = va_arg(arg_ptr, long);
	if (specifier->len_L)
		value = (long double)va_arg(arg_ptr, long double);
	else
		value = (long double)va_arg(arg_ptr, double);
	specifier->is_negative = value < 0;
	f_precision(specifier, result, &fill_precision);
	ft_ftoa(value, &holder, specifier->precision);
//	f_check_exeption(specifier, result, &value);
	f_flags(specifier, result, holder);
	if (specifier->flag_plus && !specifier->is_negative)
	{
		result->str = ft_strjoin("+", holder);
	}
//	result->str = ft_superjoin(&result->str, holder);
	if (fill_precision)
		result->str = ft_superjoin(&result->str, fill_precision);
//	f_flags(specifier, result);
	f_width(specifier, result);
//	ft_strdel(&holder);
	return (true);
}
