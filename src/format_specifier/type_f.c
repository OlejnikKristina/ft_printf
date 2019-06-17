/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_f.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/17 15:37:48 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(long double num, unsigned prec)
{
	char				*str;
	unsigned long long	value;
	long double			exponent;
	long double			real_pres = 1000000000000000000;//19;

	value = (int)num;
	exponent = (num - value) * real_pres * 100;//19
	exponent = (num - value) * 1000000000000000000;//18
	exponent = (num - value) * 100000000000000000;//17
	exponent = (num - value) * 10000000000000000;//16
	exponent = (num - value) * 1000000000000000;//15
	return (NULL);
}

bool	type_f(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	long double	value;

	if (specifier->width == STAR)
		specifier->width = va_arg(arg_ptr, long);
	if (specifier->precision == STAR)
		specifier->precision = va_arg(arg_ptr, long);
	value = (long double)va_arg(arg_ptr, double);
	ft_ftoa(value, 6);//3.14159274
	result->str = ft_strnew(0);
	return (true);
}
