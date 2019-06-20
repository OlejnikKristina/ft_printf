/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_ptr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 23:54:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/19 20:58:32 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
**	out->size += out->usage;
**	len = ft_strlen(&(*input[out->usage]));
**	ft_memmove((void *)*input, (const void *)&(*input[out->usage]), len);
**	ft_bzero((void *)&(*input[len]), len);
**
*/

void	move_ptr(char **input, char move_to, s_output *out)
{
	size_t	len;

	out->usage = findchr(*input, move_to);
	*input += findchr(*input, move_to);
}
