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
#include "libft.h"

void	set_width(s_format_spec *spec, s_placeholder *spec_res)
{
	size_t	len;
	char	*temp;

	if (spec->flag_plus)
		spec->width--;
	if (!spec->width || spec->width < spec->precision ||
	spec->width < spec->dig_amount)
		return ;
	if (spec->precision < spec->width)
		len = spec->width - spec->precision - spec->is_negative;
	if (spec->precision < spec->dig_amount)
		len = spec->width - spec->dig_amount;
	spec_res->str = ft_strnew(len);
	ft_memset((void *)spec_res->str, ' ', len);
}

void	set_sign(s_format_spec *specifier, s_placeholder *spec_res)
{
	if (specifier->flag_plus)
		spec_res->str = ft_superjoin(&spec_res->str, "+");
	if (specifier->is_negative)
		spec_res->str = ft_superjoin(&spec_res->str, "-");
}

void	length_ll(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	long long data;

	data = va_arg(arg_ptr, long long);
	specifier->is_negative = data < 0;
/*	if (specifier->is_negative)//Need MAX/MIN ll protection
	{
		specifier->dig_amount = pf_count_digit_l(data * -1);
		specifier->dig_amount += 1;
	}*/
}

bool	type_d(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	long 		type;
	char		*str_type;

	if (specifier->width == STAR)
		specifier->width = va_arg(arg_ptr, long);
	if (specifier->precision == STAR)
		specifier->precision = va_arg(arg_ptr, long);
//	if (specifier->len_ll)
//		length_ll(specifier, result, arg_ptr);
	type = va_arg(arg_ptr, long);
	specifier->dig_amount = pf_count_digit_l(type);
	specifier->is_negative = type < 0;
	str_type = pf_itoa_l(type);
	result->str = ft_strnew(0);
	set_flag_d(specifier, result, type < 0);
	set_width(specifier, result);
	set_sign(specifier, result);
	set_precision(specifier, result);
	if (type < 0)
		result->str = ft_superjoin(&result->str, &str_type[1]);
	else
		result->str = ft_superjoin(&result->str, str_type);
	ft_strdel(&str_type);
	return (true);
}
