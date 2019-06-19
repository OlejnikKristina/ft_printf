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

	if (!spec->width || spec->flag_minus ||
	spec->width <= (spec->dig_amount + spec->precision))
		return ;
	if (spec->flag_plus && !spec->is_negative && (!spec->flag_zero || spec->precision))
		spec->width--;
	if (spec->flag_hash && ft_strchr("xX", spec->type))
		spec->width -= 2;
	if (spec->precision <= spec->dig_amount)
		len = spec->width - spec->dig_amount;
	else
		len = spec->width - spec->precision;
	if (spec->flag_zero && !spec->precision && !spec->flag_minus)
	{
		spec_res->str = ft_strnew(len + spec->is_negative);
		ft_memset((void *)spec_res->str, '0', len + spec->is_negative);
		if (spec->flag_plus)
			spec_res->str[0] = '+';
		if (spec->is_negative)
			spec_res->str[0] = '-';
	}
	else
	{
		spec_res->str = ft_strnew(len);
		ft_memset((void *)spec_res->str, ' ', len);
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
	return (itoa64(data));
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
	if (spec->type == 'o')
		return (itoa_base64u(data, 8, 0));
	if (spec->type == 'x')
		return (itoa_base64u(data, 16, 0));
	if (spec->type == 'X')
		return (itoa_base64u(data, 16, 1));
	else
		return (itoa64u(data));
}

bool	integer(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	char	*str_type;

	if (
		(specifier->width == STAR && (specifier->width = va_arg(arg_ptr, long))) ||
		(specifier->precision == STAR && (specifier->precision = va_arg(arg_ptr, long))) ||
		(specifier->type == 'd' && (str_type = int_sign_length(specifier, arg_ptr))) ||
		(specifier->type == 'i' && (str_type = int_sign_length(specifier, arg_ptr))) ||
		(ft_strchr("uoxX", specifier->type) && (str_type = int_unsign_length(specifier, arg_ptr)))
		)
	;
	if (ft_strchr("oxX", specifier->type))
	{
		specifier->dig_amount = ft_strlen(str_type);
		specifier->flag_space = 0;
		specifier->flag_plus = 0;
	}
	result->str = ft_strnew(0);
	int_width(specifier, result);
	int_flag(specifier, result);
	int_precision(specifier, result);
	if (specifier->is_negative)
		result->str = ft_superjoin(&result->str, &str_type[1]);
	else
		result->str = ft_superjoin(&result->str, str_type);
	int_flag_minus(specifier, result);
	ft_strdel(&str_type);
	return (true);
}
