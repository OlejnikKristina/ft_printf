/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_f.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/19 13:48:57 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_rounding(char **float_str)
{
	int len;

	len = ft_strlen(*float_str) - 1;
	if ('5' <= (*float_str)[len] && (*float_str)[len] != '0')
	{
		if ((*float_str)[len - 1] == '9')
		{
			(*float_str)[len - 1] = '0';
			if ((*float_str)[len - 2] != '9')
				(*float_str)[len - 2] += 1;
		}
		else
			(*float_str)[len - 1] += 1;
	}
}

char	*ft_ftoa(long double num, char *float_str, unsigned precision)
{
	long double			real_pres;
	unsigned long long	exponent;
	int					value;
	unsigned 			i;
	char				*exponent_str;

	i = 0;
	real_pres = 10;
	value = (int)num;
	float_str = itoa64(value);
	(value < 0) ? value *= -1 : 1;
	(num < 0) ? num *= -1 : 1;
	if (precision)
	{
		while (i < precision)
		{
			real_pres *= 10;
			i++;
		}
		exponent = (num - value) * real_pres;
		exponent_str = itoa64u(exponent);
		float_str = ft_superjoin(&float_str, ".");
		if (exponent_str[0] == '0')
			add_zeros(0, &exponent_str, precision);
		float_str = ft_superjoin(&float_str, exponent_str);
		f_rounding(&float_str);
		float_str[ft_strlen(float_str) - 1] = '\0';
		ft_strdel(&exponent_str);
	}
	return (float_str);
}

void	f_flags(s_format_spec *s, s_placeholder *result)
{
}

void	f_flag_zero(bool is_negative, s_placeholder *result, unsigned len)
{
	char		*zero_str;
	char		*holder;

	(is_negative) ? len++ : 1;
	holder = result->str;
	zero_str = ft_strnew(len);
	ft_memset((void *)zero_str, '0', len);
	if (is_negative)
	{
		zero_str[0] = '-';
		result->str = ft_superjoin(&zero_str, &result->str[1]);
	}
	else
		result->str = ft_superjoin(&zero_str, result->str);
	ft_strdel(&zero_str);
	ft_strdel(&holder);
}

void	float_width(s_format_spec *spec, s_placeholder *result)
{
	char		*holder;
	char		*fill_width;
	int			len;

	holder = result->str;
	len = spec->width - ft_strlen(result->str);
	if (len <= 0)
		return ;
	if (spec->flag_zero)
	{
		f_flag_zero(spec->is_negative, result, len);
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

bool	type_f(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	long double		value;
	char			*fill_precision;

	fill_precision = NULL;
	if (specifier->width == STAR)
		specifier->width = va_arg(arg_ptr, long);
	if (specifier->precision == STAR)
		specifier->precision = va_arg(arg_ptr, long);
	if (specifier->len_L)
		value = (long double)va_arg(arg_ptr, long double);
	else
		value = (long double)va_arg(arg_ptr, double);
	specifier->is_negative = value < 0;
	if (19 < specifier->precision)
	{
		fill_precision = ft_strnew(specifier->precision - 19);
		ft_memset(fill_precision, '0', specifier->precision - 19);
		specifier->precision = 19;
	}
	result->str = ft_ftoa(value, result->str, specifier->precision);
	if (fill_precision)
		result->str = ft_superjoin(&result->str, fill_precision);
	float_width(specifier, result);
	f_flags(specifier, result);
	return (true);
}
