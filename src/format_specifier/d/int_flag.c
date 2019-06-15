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

void	int_sign(s_format_spec *specifier, s_placeholder *spec_res)
{
	if (specifier->is_negative)
		spec_res->str = ft_superjoin(&spec_res->str, "-");
	else if (specifier->flag_plus)
		spec_res->str = ft_superjoin(&spec_res->str, "+");
}

void	int_flag_minus(s_format_spec *spec, s_placeholder *result)
{
	int		width;
	char	*set_width;

	width = spec->width - spec->precision - spec->dig_amount;
	if (!spec->flag_minus || width <= 0)
		return ;
	set_width = ft_strnew(width+ 1);
	set_width = ft_memset((void *)set_width, ' ', width);
	result->str = ft_superjoin(&result->str, set_width);
	
}

void	int_flag_zero(s_placeholder *result, ssize_t width,
 unsigned dig_amount, bool is_negative)
{
	int			extra_zeros;

	if (width < dig_amount)
		return ;
	extra_zeros = width - dig_amount;
	result->str = ft_strnew(extra_zeros + ft_strlen(result->str));
	if (is_negative)
	{
		result->str[0] = '-';
		ft_memset(&result->str[1], '0', extra_zeros - 1);
	}
	else
		ft_memset(result->str, '0', extra_zeros);
}

void	int_flag(s_format_spec *spec, s_placeholder *spec_res,
bool is_negative)
{
	if (spec->flag_space && !is_negative)
		spec_res->str = ft_superjoin(&spec_res->str, " ");
	else if (spec->flag_zero && spec->width && !spec->precision)
		int_flag_zero(spec_res, spec->width, spec->dig_amount, is_negative);
}
