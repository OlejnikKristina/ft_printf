/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   integer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/02 12:36:11 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/24 22:59:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	int_width(s_format_spec *s, s_placeholder *result)
{
	size_t	len;

	if (!s->width || s->flag_minus || s->width <= s->precision ||
	s->width <= (s->dig_amount - s->precision))
		return (false);
	if (s->flag_plus && !s->is_negative && (!s->flag_zero || s->precision))
		s->width--;
	(s->precision < s->dig_amount) ?
	(len = s->width - s->dig_amount) :
	(len = s->width - s->precision - s->is_negative);
	if (s->flag_zero && !s->precision && !s->flag_minus)
	{
		result->str = ft_strnew(len + s->is_negative);
		ft_memset((void *)result->str, '0', len + s->is_negative);
		(s->flag_plus) ? result->str[0] = '+' : 1;
		(s->is_negative) ? result->str[0] = '-' : 1;
		(s->flag_space) ? result->str[0] = ' ' : 1;
	}
	else
	{
		result->str = ft_strnew(len);
		ft_memset((void *)result->str, ' ', len);
	}
	return (true);
}

char	*int_sign_len(s_format_spec *spec, va_list arg_ptr)
{
	int64_t		data;

	if (spec->len_l)
		data = va_arg(arg_ptr, long);
	else if (spec->len_ll)
		data = va_arg(arg_ptr, long long);
	else if (spec->len_h)
		data = (short)va_arg(arg_ptr, int);
	else if (spec->len_hh)
		data = (char)va_arg(arg_ptr, int);
	else
		data = va_arg(arg_ptr, int);
	if (spec->precision == DOT_ZERO && data == 0)
	{
		spec->precision = 0;
		return (ft_strnew(0));
	}
	spec->is_negative = data < 0;
	spec->dig_amount = count_digit64(data);
	if (spec->flag_space && (spec->precision < spec->width))
		spec->width -= 1;
	return (itoa64(data));
}

char	*int_unsign_len(s_format_spec *spec, va_list arg_ptr)
{
	uint64_t		data;
	if (spec->len_l)
		data = va_arg(arg_ptr, unsigned long);
	else if (spec->len_ll)
		data = va_arg(arg_ptr, unsigned long long);
	else if (spec->len_h)
		data = (unsigned short)va_arg(arg_ptr, int);
	else if (spec->len_hh)
		data = (unsigned char)va_arg(arg_ptr, int);
	else
		data = va_arg(arg_ptr, unsigned int);
	spec->dig_amount = count_digit64u(data);
	if (spec->precision == -42 && (spec->type != 'o' || !spec->flag_hash))
	{
		spec->precision = 0;
		spec->flag_hash = 0;
		return (ft_strnew(0));
	}
	if (spec->flag_hash && ft_strchr("xX", spec->type)
	&& (!spec->flag_zero || spec->flag_minus))
		(spec->width -= 2);
	if (spec->type == 'o' && spec->flag_hash)
		spec->width -= 1;
	if (spec->type == 'o')
		return (itoa_base64u(data, 8, 0));
	if (spec->type == 'x')
		return (itoa_base64u(data, 16, 0));
	if (spec->type == 'X')
		return (itoa_base64u(data, 16, 1));
	else
		return (itoa64u(data));
}

void	integer(s_format_spec *s, s_placeholder *result, va_list arg_ptr)
{
	char	*type;

	if (
		(s->width == STAR && (s->width = va_arg(arg_ptr, long))) ||
		(s->precision == STAR && (s->precision = va_arg(arg_ptr, long))) ||
		(s->type == 'd' && (type = int_sign_len(s, arg_ptr))) ||
		(s->type == 'i' && (type = int_sign_len(s, arg_ptr))) ||
		(ft_strchr("uoxX", s->type) && (type = int_unsign_len(s, arg_ptr))))
		;
	if (ft_strchr("ouxX", s->type))
	{
		s->dig_amount = ft_strlen(type);
		s->flag_space = 0;
		s->flag_plus = 0;
	}
	if (!int_width(s, result))
		result->str = ft_strnew(0);
	int_flag(s, result, type);
	int_precision(s, result);
	(!s->is_negative || (!s->width && s->flag_zero && s->is_negative)
	|| (s->is_negative && s->flag_zero && s->flag_minus))
	? (result->str = ft_superjoin(&result->str, type)) :
	(result->str = ft_superjoin(&result->str, &type[1])) ;
	int_flag_minus(s, result);
	ft_strdel(&type);
}
