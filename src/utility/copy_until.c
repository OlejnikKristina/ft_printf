/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_until.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 23:52:32 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/19 20:54:14 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	copy_until(char *src, s_output *out, char percent)
{
	int		copy_to;
	char	*temp;
	char	*cut_str;

	temp = out->str;
	copy_to = findchr(src, percent);
	if (copy_to == -1)
	{
		out->str = ft_strjoin(out->str, src);
		out->size += ft_strlen(src);
	}
	else
	{
		cut_str = ft_strsub(src, 0, copy_to);
		out->str = ft_strjoin(out->str, cut_str);
		ft_strdel(&cut_str);
		out->size += copy_to;
	}
	ft_strdel(&temp);
	return ((copy_to == -1) ? FINISHED : COMPLITED);
}
