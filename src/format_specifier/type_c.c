/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/23 16:42:27 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	type_c(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	char	symbol[5];
	char	*width_minus;

	ft_strclr(symbol);
	symbol[0] = (char)va_arg(arg_ptr, int);
	if (symbol[0] == 0)
	{
		symbol[0] = '\0';
		specifier->usage += 1;
		return (0);
	}
	if (1 < specifier->width && !specifier->flag_minus)
	{
		result->str = ft_strnew(specifier->width + 1);
		specifier->width -= 1;
		(specifier->flag_zero) ?
		ft_memset((void *)result->str, '0', specifier->width) :
		ft_memset((void *)result->str, ' ', specifier->width);
	}
	else
		result->str = ft_strnew(0);
	result->str = ft_superjoin(&result->str, symbol);
	if (1 < specifier->width && specifier->flag_minus)
	{
		width_minus = ft_strnew(specifier->width - 1);
		ft_memset((void *)width_minus, ' ', specifier->width - 1);
		result->str = ft_superjoin(&result->str, width_minus);
		ft_strdel(&width_minus);
	}
	return (true);
}
