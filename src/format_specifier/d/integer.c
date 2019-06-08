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

void	int_width(s_format_spec *spec, s_placeholder *spec_res)
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

void	int_sign(s_format_spec *specifier, s_placeholder *spec_res)
{
	if (specifier->flag_plus)
		spec_res->str = ft_superjoin(&spec_res->str, "+");
	if (specifier->is_negative)
		spec_res->str = ft_superjoin(&spec_res->str, "-");
}

bool	integer(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	char	*str_type;

	if (specifier->width == STAR)
		specifier->width = va_arg(arg_ptr, long);
	if (specifier->precision == STAR)
		specifier->precision = va_arg(arg_ptr, long);
	if (specifier->type == 'd')
		str_type = int_sign_length(specifier, arg_ptr);
	else if (specifier->type == 'u')
		str_type = int_unsign_length(specifier, arg_ptr);
	else
		return (0);
	result->str = ft_strnew(0);
	int_flag(specifier, result, specifier->is_negative);
	int_width(specifier, result);
	int_sign(specifier, result);
	int_precision(specifier, result);
	if (specifier->is_negative)
		result->str = ft_superjoin(&result->str, &str_type[1]);
	else
		result->str = ft_superjoin(&result->str, str_type);
	ft_strdel(&str_type);
	return (true);
}
