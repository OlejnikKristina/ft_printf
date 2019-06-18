/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_flag_d.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 23:29:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/07 23:29:00 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_flag(s_format_spec *specifier, s_placeholder *spec_res)
{
	if (specifier->is_negative)
		spec_res->str = ft_superjoin(&spec_res->str, "-");
	if (specifier->flag_plus)
		spec_res->str = ft_superjoin(&spec_res->str, "+");
	if (specifier->flag_space)
		spec_res->str = ft_superjoin(&spec_res->str, " ");
	if (specifier->flag_hash && specifier->type == 'x')
		spec_res->str = ft_superjoin(&spec_res->str, "0x");
	if (specifier->flag_hash && specifier->type == 'X')
		spec_res->str = ft_superjoin(&spec_res->str, "0X");
}

void	int_flag_minus(s_format_spec *spec, s_placeholder *result)
{
	int		width;
	char	*set_width;

	if (spec->precision <= spec->dig_amount)
		width = spec->width - spec->dig_amount;
	else
		width = spec->width - spec->precision;
	if (!spec->flag_minus || width <= 0)
		return ;
	set_width = ft_strnew(width + 1);
	set_width = ft_memset((void *)set_width, ' ', width);
	result->str = ft_superjoin(&result->str, set_width);
}
