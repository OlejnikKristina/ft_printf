/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/26 12:25:31 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static	void	p_width(s_format_spec *s, s_placeholder *result, char *address_str)
{
	int			len;
	char		sign;
	char		*minus_flag;

	(s->flag_zero) ?
	(sign = '0') :
	(sign = ' ');
	len = s->width - s->dig_amount;
	if (0 < len && !s->flag_minus)
	{
		result->str = ft_strnew(len);
		ft_memset((void *)result->str, sign, len);
		result->str = ft_superjoin(&result->str, address_str);
		if (s->flag_zero)
		{
			result->str[1] = 'x';
			result->str[len + 1] = '0';
		}
	}
	else if (0 < len && s->flag_minus)
	{
		result->str = ft_strdup(address_str);
		minus_flag = ft_strnew(len);
		ft_memset((void *)minus_flag, sign, len);
		result->str = ft_superjoin(&result->str, minus_flag);
		ft_strdel(&minus_flag);
	}
	else
		result->str = ft_strdup(address_str);
}*/

static	void	p_width(s_format_spec *s, s_placeholder *result)
{
	int			len;
	char		sign;
	char		*minus_flag;
	char		*add_space;
	char		*holder;

	(s->flag_zero) ?
	(sign = '0') :
	(sign = ' ');//35 - 22 = 13;
	len = s->width - s->dig_amount;
	if (len <= 0)
		return ;
	if (!s->flag_minus)
	{
		add_space = ft_strnew(len);
		ft_memset((void *)add_space, sign, len);
		holder = result->str;
		result->str = ft_superjoin(&add_space, result->str);
		ft_strdel(&holder);
		if (s->flag_zero)
		{
			result->str[1] = 'x';
			result->str[len + 1] = '0';
		}
	}
	else if (s->flag_minus)
	{
		add_space = ft_strnew(len);
		ft_memset((void *)add_space, sign, len);
		result->str = ft_superjoin(&result->str, add_space);
		ft_strdel(&add_space);
	}
}

static	void	p_precision(s_format_spec *s, s_placeholder *result, char *address_str)
{
	char	*fill_precis;
	int		prec_size;

	if (s->precision <= s->dig_amount)
		result->str = ft_strdup("0x");
	else
	{
		prec_size = s->precision - s->dig_amount;
		fill_precis = ft_strnew(prec_size + 3);
		ft_memset(fill_precis, '0', prec_size + 2);
		result->str = ft_strdup(fill_precis);
		result->str[1] = 'x';
		ft_strdel(&fill_precis);
	}
	result->str = ft_superjoin(&result->str, address_str);
	s->dig_amount = ft_strlen(result->str);
}

bool	type_p(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	int64_t		address;
	char		*address_str;

	address = va_arg(arg_ptr, long long);
	if (address == 0 && specifier->precision == -42)
		specifier->precision = 0;
	else
		address_str = itoa_base64(address, 16, 0);
	specifier->dig_amount = ft_strlen(address_str);
	p_precision(specifier, result, address_str);
	p_width(specifier, result);
	ft_strdel(&address_str);
	return (true);
}
