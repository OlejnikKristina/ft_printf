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

static char	*length_llu(s_format_spec *specifier, va_list arg_ptr)
{
	unsigned long long	data;

	data = va_arg(arg_ptr, unsigned long long);
	specifier->is_negative = 0;
	specifier->dig_amount = pf_count_digit_llu(data);
	return (pf_itoa_llu(data));
}

static char	*length_lu(s_format_spec *specifier, va_list arg_ptr)
{
	unsigned long	data;

	data = va_arg(arg_ptr, unsigned long);
	specifier->is_negative = 0;
	specifier->dig_amount = pf_count_digit_lu(data);
	return (pf_itoa_lu(data));
}


static char	*orig_unsig_int(s_format_spec *specifier, va_list arg_ptr)
{
	unsigned	data;

	data = va_arg(arg_ptr, unsigned);
	specifier->is_negative = 0;
	specifier->dig_amount = pf_count_digit_ll(data);
	return (pf_itoa_ll(data));
}

static char	*length_hh(s_format_spec *specifier, va_list arg_ptr)
{
	unsigned char data;

	data = va_arg(arg_ptr, unsigned char);
	specifier->is_negative = 0;
	specifier->dig_amount = ft_count_digit((int)data);
	return (ft_itoa((int)data));
}

char	*int_unsign_length(s_format_spec *specifier, va_list arg_ptr)
{
	if (specifier->len_ll)
		return (length_llu(specifier, arg_ptr));
	else if (specifier->len_l)
		return (length_lu(specifier, arg_ptr));
	else if (specifier->len_h)
		return (orig_int(specifier, arg_ptr));
	else if (specifier->len_hh)
		return (length_hh(specifier, arg_ptr));
	else
		return (orig_unsig_int(specifier, arg_ptr));
}
