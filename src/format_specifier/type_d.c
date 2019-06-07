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

void	flag_zero_type_d(s_placeholder *result, ssize_t width,
 unsigned dig_amount, bool is_negative)
{
	int			extra_zeros;

	if (width < dig_amount)
		return ;
	extra_zeros = width - dig_amount;
	result->str = ft_strnew(extra_zeros + ft_strlen(result->str));
	if (is_negative)
	{
		result->str[0] = '-';
		ft_memset(&result->str[1], '0', extra_zeros - 1);
	}
	else
		ft_memset(result->str, '0', extra_zeros);
}

bool	add_zeros(unsigned dig_amount, char **result, ssize_t width)
{
	int			extra_zeros;
	char		*zeros_str;

	if (width < dig_amount)
		return (false);
	extra_zeros = width - dig_amount;
	zeros_str = ft_strnew(extra_zeros);
	ft_memset(zeros_str, '0', extra_zeros);
	*result = ft_superjoin(result, zeros_str);
	ft_strdel(&zeros_str);
	return (true);
}

void	set_flag_d(s_format_spec *spec, s_placeholder *spec_res,
bool is_negative)
{
	if (spec->flag_space && !is_negative)
		spec_res->str = ft_superjoin(&spec_res->str, " ");
	else if (spec->flag_zero && spec->width && !spec->precision)
		flag_zero_type_d(spec_res, spec->width, spec->dig_amount, is_negative);

}

bool	set_precision(s_format_spec *spec, s_placeholder *spec_res)
{
	size_t	len;

	len = ft_strlen(spec_res->str);
	if (!spec->precision)
		return (false);
	if (spec->is_negative)
		spec->precision += 1;
	add_zeros(spec->dig_amount, &spec_res->str, spec->precision);
	return (true);
}

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

bool	type_d(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	long	type;
	char	*str_type;

	if (specifier->width == STAR)
		specifier->width = va_arg(arg_ptr, long);
	if (specifier->precision == STAR)
		specifier->precision = va_arg(arg_ptr, long);
	type = va_arg(arg_ptr, int);
	specifier->dig_amount = pf_count_digit_l(type);
	specifier->is_negative = type < 0;
//	printf("%u\n", specifier->is_negative);
//	(type < MIN_INT || type > MAX_INT) ? type = 0 : 1;
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
