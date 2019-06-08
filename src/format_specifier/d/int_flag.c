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
