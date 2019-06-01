/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_superjoin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/01 16:10:38 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/01 16:10:38 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_superjoin(char **s1, char const *s2)
{
	char		*newstr;
	char		*temp;
	size_t		len_s1;

	len_s1 = ft_strlen(*s1);
	temp = *s1;
	newstr = ft_strnew(len_s1 + ft_strlen(s2));
	if (!newstr)
		return (NULL);
	newstr = ft_strcpy(newstr, *s1);
	newstr = ft_strcpy(newstr + len_s1, s2);
	ft_strdel(&temp);
	*s1 = &newstr[-len_s1];
	return (&newstr[-len_s1]);
}
