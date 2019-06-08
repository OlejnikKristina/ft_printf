/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_precision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 23:39:59 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/07 23:39:59 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_zeros(unsigned dig_amount, char **result, ssize_t width)
{
	int			extra_zeros;
	char		*zeros_str;

	if (width < dig_amount)
		return ;
	extra_zeros = width - dig_amount;
	zeros_str = ft_strnew(extra_zeros);
	ft_memset(zeros_str, '0', extra_zeros);
	*result = ft_superjoin(result, zeros_str);
	ft_strdel(&zeros_str);
	return ;
}

void	int_precision(s_format_spec *spec, s_placeholder *spec_res)
{
	if (!spec->precision)
		return ;
	if (spec->is_negative)
		spec->precision += 1;
	add_zeros(spec->dig_amount, &spec_res->str, spec->precision);
	return ;
}
