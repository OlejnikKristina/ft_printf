/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:41 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/01 16:02:06 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_elem;

	if (!alst || !*alst || !(*del))
		return ;
	while (*alst != NULL)
	{
		next_elem = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content_size = 0;
		free(*alst);
		*alst = NULL;
		*alst = next_elem;
	}
}
