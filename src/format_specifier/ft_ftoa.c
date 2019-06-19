/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/19 20:32:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	f_rounding(char **float_str)
{
	int len;

	len = ft_strlen(*float_str) - 1;
	if ('5' <= (*float_str)[len] && (*float_str)[len] != '0')
	{
		if ((*float_str)[len - 1] == '9')
		{
			(*float_str)[len - 1] = '0';
			if ((*float_str)[len - 2] != '9')
				(*float_str)[len - 2] += 1;
		}
		else
			(*float_str)[len - 1] += 1;
	}
}

static void	f_add_exponent(char **exponent_str, char **float_str, unsigned precision)
{
	*float_str = ft_superjoin(float_str, ".");
	if (*exponent_str[0] == '0')
		add_zeros(0, exponent_str, precision);
	*float_str = ft_superjoin(float_str, *exponent_str);
	f_rounding(float_str);
	ft_strdel(exponent_str);
}

char	*ft_ftoa(long double num, char *float_str, unsigned precision)
{
	long double			real_pres;
	unsigned long long	exponent;
	unsigned			i;
	int					value;
	char				*exponent_str;

	i = 0;
	real_pres = 10;
	value = (int)num;
	float_str = itoa64(value);
	(value < 0) ? value *= -1 : 1;
	(num < 0) ? num *= -1 : 1;
	if (precision)
	{
		while (i < precision)
		{
			real_pres *= 10;
			i++;
		}
		exponent = (num - value) * real_pres;
		exponent_str = itoa64u(exponent);
		f_add_exponent(&exponent_str, &float_str, precision);
		float_str[ft_strlen(float_str) - 1] = '\0';
	}
	return (float_str);
}
