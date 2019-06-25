/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/25 19:46:19 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
}

bool	type_p(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	int64_t		address;
//	unsigned	len;
	char		*address_str;

	address = va_arg(arg_ptr, long long);
	address_str = ft_strdup("0x");
	address_str = ft_superjoin(&address_str, itoa_base64(address, 16, 0));
//	len = ft_strlen(address_str);
	specifier->dig_amount = ft_strlen(address_str);
	p_width(specifier, result, address_str);
/*	if (len < specifier->width)
	{
		len = specifier->width - len;
		result->str = ft_strnew(len);
		ft_memset((void *)result->str, ' ', len);
	}
	else
		result->str = ft_strnew(0);
	result->str = ft_superjoin(&result->str, address_str);*/
	ft_strdel(&address_str);
	return (true);
}
