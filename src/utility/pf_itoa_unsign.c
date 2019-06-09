/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_itoa_unsign.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 18:06:13 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/08 18:06:13 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned	pf_count_digit_lu(unsigned long nbr)
{
	unsigned amount;

	amount = 0;
	if (nbr <= 0)
	{
		nbr *= (-1);
		amount++;
	}
	while (nbr)
	{
		nbr /= 10;
		amount++;
	}
	return (amount);
}

char	*pf_itoa_lu(unsigned long nbr)
{
	int32_t	digit_amount;
	bool	sign;
	char	*str;

	sign = 0;
	digit_amount = pf_count_digit_lu(nbr);
	str = (char *)malloc(digit_amount + 1);
	str[digit_amount] = '\0';
	digit_amount--;
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	while (0 <= digit_amount)
	{
		str[digit_amount] = nbr % 10 + '0';
		nbr /= 10;
		--digit_amount;
	}
	(sign) ? str[0] = '-' : 1;
	return (str);
}

unsigned	pf_count_digit_llu(unsigned long long nbr)
{
	unsigned amount;

	amount = 0;
	if (nbr <= 0)
	{
		nbr *= (-1);
		amount++;
	}
	while (nbr)
	{
		nbr /= 10;
		amount++;
	}
	return (amount);
}

char	*pf_itoa_llu(unsigned long long nbr)
{
	int32_t	digit_amount;
	bool	sign;
	char	*str;

	sign = 0;
	digit_amount = pf_count_digit_llu(nbr);
	str = (char *)malloc(digit_amount + 1);
	str[digit_amount] = '\0';
	digit_amount--;
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	while (0 <= digit_amount)
	{
		str[digit_amount] = nbr % 10 + '0';
		nbr /= 10;
		--digit_amount;
	}
	(sign) ? str[0] = '-' : 1;
	return (str);
}
