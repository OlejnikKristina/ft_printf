/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/16 20:24:02 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	type_s(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	char	*line;

	line = ft_strnew(20);
	if (specifier->width == STAR)
		(specifier->width = va_arg(arg_ptr, long));
	if (specifier->precision == STAR)
		(specifier->precision = va_arg(arg_ptr, long));
	line = va_arg(arg_ptr, char*);
	printf("line: %s\n", line);
	return (true);
}