/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_flag.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 23:29:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/21 16:06:35 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_flag(s_format_spec *spec, s_placeholder *spec_res)
{
	if (spec->is_negative && (!spec->flag_zero || spec->precision))
		spec_res->str = ft_superjoin(&spec_res->str, "-");
	if (spec->flag_plus && (!spec->flag_zero || spec->precision)
	&& !spec->is_negative)
		spec_res->str = ft_superjoin(&spec_res->str, "+");
	if (spec->flag_space && !spec->flag_zero)
		spec_res->str = ft_superjoin(&spec_res->str, " ");
	if (spec->flag_hash && spec->type == 'x')
		spec_res->str = ft_superjoin(&spec_res->str, "0x");
	if (spec->flag_hash && spec->type == 'X')
		spec_res->str = ft_superjoin(&spec_res->str, "0X");
}

void	int_flag_minus(s_format_spec *spec, s_placeholder *result)
{
	int		width;
	char	*set_width;

	if (spec->precision <= spec->dig_amount)
		width = spec->width - spec->dig_amount
		- ((spec->flag_plus && !spec->is_negative) || spec->flag_space);
	else
		width = spec->width - spec->precision
		- ((spec->flag_plus && !spec->is_negative) || spec->flag_space);
	if (!spec->flag_minus || width <= 0)
		return ;
	set_width = ft_strnew(width + 1);
	set_width = ft_memset((void *)set_width, ' ', width);
	result->str = ft_superjoin(&result->str, set_width);
}
