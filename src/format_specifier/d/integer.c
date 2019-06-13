/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_d.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/02 12:36:11 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/02 12:36:11 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_width(s_format_spec *spec, s_placeholder *spec_res)
{
	size_t	len;
	char	*temp;

	if (spec->flag_plus || spec->is_negative)
		spec->width--;
	if (!spec->width || spec->width < spec->precision ||
	spec->width < spec->dig_amount)
		return ;
	if (
		(spec->precision <= spec->width && (len = spec->width - spec->precision)) ||
		(spec->precision <= spec->dig_amount && (len = spec->width - spec->dig_amount)))
	{
		if (!spec->flag_minus)
		{
			spec_res->str = ft_strnew(len);
			ft_memset((void *)spec_res->str, ' ', len);
		}
		else
			spec->width = len;
	}
}

void	int_precision(s_format_spec *spec, s_placeholder *spec_res)
{
	if (!spec->precision)
		return ;
	if (spec->is_negative)
		spec->precision += 1;
	add_zeros(spec->dig_amount, &spec_res->str, spec->precision);
}

char	*int_sign_length(s_format_spec *spec, va_list arg_ptr)
{
	int64_t		data;

	if (
		(spec->len_ll && (data = va_arg(arg_ptr, long long))) ||
		(spec->len_l && (data = va_arg(arg_ptr, long))) ||
		(spec->len_h && (data = (short)va_arg(arg_ptr, int))) ||
		(spec->len_hh && (data = (char)va_arg(arg_ptr, int))) ||
		(data = va_arg(arg_ptr, int)))
		;
	else
		data = 0;
	spec->is_negative = data < 0;
	spec->dig_amount = count_digit64(data);
	return (ft_itoa64(data));
}

char	*int_unsign_length(s_format_spec *spec, va_list arg_ptr)
{
	uint64_t		data;

	if (
		(spec->len_ll && (data = va_arg(arg_ptr, unsigned long long))) ||
		(spec->len_l && (data = va_arg(arg_ptr, unsigned long))) ||
		(spec->len_h && (data = (unsigned short)va_arg(arg_ptr, int))) ||
		(spec->len_hh && (data = (unsigned char)va_arg(arg_ptr, int))) ||
		(data = va_arg(arg_ptr, unsigned int)))
		;
	else
		data = 0;
	spec->dig_amount = count_digit64u(data);
	return (ft_itoa64u(data));
}

bool	integer(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	char	*str_type;

	if (
		(specifier->width == STAR && (specifier->width = va_arg(arg_ptr, long))) ||
		(specifier->precision == STAR && (specifier->precision = va_arg(arg_ptr, long))) ||
		(specifier->type == 'd' && (str_type = int_sign_length(specifier, arg_ptr))) ||
		(specifier->type == 'i' && (str_type = int_sign_length(specifier, arg_ptr))) ||
		(specifier->type == 'u' && (str_type = int_unsign_length(specifier, arg_ptr))))
	;
	result->str = ft_strnew(0);
	int_flag(specifier, result, specifier->is_negative);
	int_width(specifier, result);
	int_sign(specifier, result);
	int_precision(specifier, result);
	if (specifier->is_negative)
		result->str = ft_superjoin(&result->str, &str_type[1]);
	else
		result->str = ft_superjoin(&result->str, str_type);
	int_flag_minus(specifier, result);
	ft_strdel(&str_type);
	return (true);
}
