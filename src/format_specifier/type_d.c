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

bool	flag_zero_type_d(s_placeholder *result, ssize_t width,
long type, char zero_space)
{
	unsigned	dig_amount;
	int			extra_zeros;

	dig_amount = ft_count_digit(type);
	if (width < dig_amount)
		return (false);
	extra_zeros = width - dig_amount;
//	if (result->str)
//		free(&result->str);
	result->str = ft_strnew(extra_zeros + ft_strlen(result->str));
	if (type < 0)
	{
		result->str[0] = '-';
		ft_memset(&result->str[1], zero_space, extra_zeros - 1);
	}
	else
		ft_memset(result->str, zero_space, extra_zeros);
	return (true);
}

bool	add_zeros(char **result, ssize_t width,
long type, char zero_space)
{
	unsigned	dig_amount;
	int			extra_zeros;
	char		*zeros_str;

	dig_amount = ft_count_digit(type);//3
	if (width < dig_amount)
		return (false);
	extra_zeros = width - dig_amount;
	zeros_str = ft_strnew(extra_zeros);
	if (type < 0)
	{
		zeros_str = ft_memset((void *)zeros_str, zero_space, extra_zeros - 1);
	//	*result = ft_superjoin(result, "-");
		*result = ft_superjoin(result, zeros_str);
	}
	else
	{
		ft_memset(zeros_str, zero_space, extra_zeros);
		*result = ft_superjoin(result, zeros_str);
	}
	ft_strdel(&zeros_str);
	return (true);
}

bool	set_flag_d(s_format_spec *spec, s_placeholder *spec_res,
long type)
{
	if (spec->flag_space && 0 <= type)
		spec_res->str = ft_superjoin(&spec_res->str, " ");
	else if (spec->flag_plus && 0 <= type)
		spec_res->str = ft_superjoin(&spec_res->str, "+");
	else if (spec->flag_zero && spec->width && !spec->precision)
		flag_zero_type_d(spec_res, spec->width, type, '0');
	else
		return (false);
	return (true);
}

bool	set_precision(s_format_spec *spec, s_placeholder *spec_res,
long type)
{
	size_t	len;

	len = ft_strlen(spec_res->str);
	if (!spec->precision)
		return (false);
	if (type < 0)
		spec->precision += 1;
	add_zeros(&spec_res->str, spec->precision, type, '0');
	return (true);
}

void	set_width(s_format_spec *spec, s_placeholder *spec_res,
long type)
{
	size_t	len;
	int		digit_amount;
	char	*temp;
	char	*set_width;

	digit_amount = ft_count_digit(type);
	if (spec->flag_plus)
		spec->width--;
	if (!spec->width || spec->width < spec->precision ||
	spec->width < digit_amount)
		return ;
	if (spec->precision < spec->width)
		len = spec->width - spec->precision;
	if (spec->precision < digit_amount)
		len = spec->width - digit_amount;
	if (type < 0)
		len--;
	spec_res->str = ft_strnew(len);
	ft_memset((void *)spec_res->str, ' ', len);
}
/*
	if (type < MIN_INT || type > MAX_INT)
		type = 0;
*/
bool	type_d(s_format_spec *specifier, s_placeholder *spec_res, va_list arg_ptr)
{
	long	type;
	char	*str_type;

	if (specifier->width == STAR)
		specifier->width = va_arg(arg_ptr, long);
	if (specifier->precision == STAR)
		specifier->precision = va_arg(arg_ptr, long);
	type = va_arg(arg_ptr, int);
	str_type = ft_itoa(type);
	spec_res->str = ft_strnew(0);
	set_flag_d(specifier, spec_res, type);
	set_width(specifier, spec_res, type);
	if (specifier->flag_plus)
		spec_res->str = ft_superjoin(&spec_res->str, "+");
	if (type < 0)
		spec_res->str = ft_superjoin(&spec_res->str, "-");
	set_precision(specifier, spec_res, type);
	if (type < 0)
		spec_res->str = ft_superjoin(&spec_res->str, &str_type[1]);
	else
		spec_res->str = ft_superjoin(&spec_res->str, str_type);
	ft_strdel(&str_type);
	return (true);
}
