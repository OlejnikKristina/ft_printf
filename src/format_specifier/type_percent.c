/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_percent.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/21 19:20:17 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	type_percent(s_format_spec *s, s_placeholder *result, va_list arg_ptr)
{
	if (s->width == STAR)
		s->width = va_arg(arg_ptr, long);
	s->dig_amount = 1;
	result->str = ft_strnew(0);
	int_width(s, result);
	result->str = ft_superjoin(&result->str, "%");
	int_flag_minus(s, result);
	return (true);
}
