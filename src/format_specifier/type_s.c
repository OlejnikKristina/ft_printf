/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/19 19:13:32 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	type_s(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	char	*line;

	if (specifier->precision == STAR)
		(specifier->precision = va_arg(arg_ptr, long));
	line = va_arg(arg_ptr, char *);
	if (specifier->precision == -42)
	{
		result->str = ft_strnew(0);
		return (true);
	}
	if (specifier->precision < 0)
		specifier->precision *= -1;
	if (specifier->precision)
		result->str = ft_strsub((char const *)line, 0, specifier->precision);
	else
		result->str = ft_strdup(line);
	return (true);
}
