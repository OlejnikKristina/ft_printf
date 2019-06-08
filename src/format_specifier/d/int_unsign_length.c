/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_unsign_length.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 17:56:28 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/08 17:56:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*length_ull(s_format_spec *specifier, va_list arg_ptr)
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

static char	*length_ul(s_format_spec *specifier, va_list arg_ptr)
{
	long	data;

	data = va_arg(arg_ptr, long);
	specifier->is_negative = data < 0;
	specifier->dig_amount = pf_count_digit_l(data);
	return (pf_itoa_l(data));
}

static char	*orig_unsig_int(s_format_spec *specifier, va_list arg_ptr)
{
	unsigned	data;

	data = va_arg(arg_ptr, unsigned);
	specifier->is_negative = data < 0;
	specifier->dig_amount = pf_count_digit_ll((unsigned)data);
	return (pf_itoa_ll((unsigned)data));
}

static char	*length_uh(s_format_spec *specifier, va_list arg_ptr)
{
	int	data;

	data = (short)va_arg(arg_ptr, int);
	specifier->is_negative = data < 0;
	specifier->dig_amount = ft_count_digit(data);
	return (ft_itoa(data));
}

char	*int_unsign_length(s_format_spec *specifier, va_list arg_ptr)
{
	if (specifier->len_ll)
		return (length_ull(specifier, arg_ptr));
	else if (specifier->len_l)
		return (length_ul(specifier, arg_ptr));
	else if (specifier->len_h)
		return (orig_int(specifier, arg_ptr));
	else
		return (orig_unsig_int(specifier, arg_ptr));
}
