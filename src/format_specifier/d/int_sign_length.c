/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_signed_len.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 17:57:24 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/08 17:57:24 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*length_ll(s_format_spec *specifier, va_list arg_ptr)
{
	long long	data;

	data = va_arg(arg_ptr, long long);
	specifier->is_negative = data < 0;
	if (data < MIN_LL)
	{
		specifier->dig_amount = 20;
		return (ft_strdup("-9223372036854775808"));
	}
	specifier->dig_amount = pf_count_digit_ll(data);
	return (pf_itoa_ll(data));
}

static char	*length_l(s_format_spec *specifier, va_list arg_ptr)
{
	long	data;

	data = va_arg(arg_ptr, long);
	specifier->is_negative = data < 0;
	specifier->dig_amount = pf_count_digit_l(data);
	return (pf_itoa_l(data));
}

char	*orig_int(s_format_spec *specifier, va_list arg_ptr)
{
	int	data;

	data = va_arg(arg_ptr, int);
	specifier->is_negative = data < 0;
	specifier->dig_amount = ft_count_digit(data);
	return (ft_itoa(data));
}

static char	*length_h(s_format_spec *specifier, va_list arg_ptr)
{
	short	data;

	data = (short)va_arg(arg_ptr, int);
	specifier->is_negative = data < 0;
	specifier->dig_amount = ft_count_digit((int)data);
	return (ft_itoa(data));
}

char	*int_sign_length(s_format_spec *specifier, va_list arg_ptr)
{
	if (specifier->len_ll)
		return (length_ll(specifier, arg_ptr));
	else if (specifier->len_l)
		return (length_l(specifier, arg_ptr));
	else if (specifier->len_h)
		return (length_h(specifier, arg_ptr));
	else
		return (orig_int(specifier, arg_ptr));
}
