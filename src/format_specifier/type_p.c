/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/17 11:57:13 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	type_p(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	int64_t		address;
	unsigned	len;
	char		*address_str;

	address = va_arg(arg_ptr, long long);
	address_str = ft_strdup("0x");
	address_str = ft_superjoin(&address_str, itoa_base64(address, 16, 0));
	len = ft_strlen(address_str);
	if (len < specifier->width)
	{
		len = specifier->width - len;
		result->str = ft_strnew(len);
		ft_memset((void *)result->str, ' ', len);
	}
	else
		result->str = ft_strnew(0);
	result->str = ft_superjoin(&result->str, address_str);
	ft_strdel(&address_str);
	return (true);
}
