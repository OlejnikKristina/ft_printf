/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_oxX.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 15:24:15 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/09 15:24:15 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(int value, short base)
{
	char		*num;
	char		*reverse_num;
	unsigned	dig_amount
	unsigned	i;

	if (base < 10)
	{
		dig_amount = ft_count_digit(value);
		num = ft_strnew(dig_amount);
		num[dig_amount] = '\0';
		dig_amount--;
		while(dig_amount)
		{
			if (value == base)
				num[dig_amount] = 1 + '0';
			else
				num[dig_amount] = value % base + '0';
			value /= base;
			dig_amount--;
		}
		printf("value: %s\n", num);
	}
	return (NULL);
}

bool	type_oxX(s_format_spec *spec, s_placeholder *spec_res)
{
	return (true);
}