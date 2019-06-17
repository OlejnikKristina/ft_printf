/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/17 11:05:56 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	type_p(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	int64_t	address;

	address = va_arg(arg_ptr, long long);
	result->str = ft_strdup("0x");
	result->str = ft_superjoin(&result->str, itoa_base64(address, 16, 0));
	return (true);
}
