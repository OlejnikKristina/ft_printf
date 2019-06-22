/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 23:52:32 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/22 15:30:15 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrev(char str_rev[])
{
	unsigned	i;
	unsigned	end_str;
	char		temp;

	i = 0;
	end_str = ft_strlen(str_rev);
	end_str--;
	while (i <= (end_str + 1) / 2)
	{
		temp = str_rev[i];
		str_rev[i] = str_rev[end_str];
		str_rev[end_str] = temp;
		end_str--;
		i++;
	}
	str_rev[ft_strlen(str_rev)] = '\0';
	return (NULL);
}
