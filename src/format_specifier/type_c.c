/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/16 20:02:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	type_c(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	char	*symbol;
	char	*width_minus;

	symbol = ft_strnew(5);
	symbol[0] = (char)va_arg(arg_ptr, int);
	if (1 < specifier->width && !specifier->flag_minus)
	{
		result->str = ft_strnew(specifier->width);
		specifier->width -= 1;
		if (specifier->flag_zero)
			ft_memset((void *)result->str, '0', specifier->width);
		else
			ft_memset((void *)result->str, ' ', specifier->width);
	}
	else
		result->str = ft_strnew(0);
	result->str = ft_superjoin(&result->str, symbol);
	if (1 < specifier->width && specifier->flag_minus)
	{
		specifier->width -= 1;
		width_minus = ft_strnew(specifier->width);
		ft_memset((void *)width_minus, ' ', specifier->width);
		result->str = ft_superjoin(&result->str, width_minus);
		ft_strdel(&width_minus);
	}
	ft_strdel(&symbol);
	return (true);
}
