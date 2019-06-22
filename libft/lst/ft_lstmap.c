/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 13:53:49 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/13 14:41:31 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new_elem;
	t_list	*top_new;

	new_elem = f(lst);
	if (!new_elem)
		return (NULL);
	top_new = new_elem;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_elem->next = f(lst);
		if (!new_elem->next)
			return (NULL);
		new_elem = new_elem->next;
	}
	new_elem->next = NULL;
	return (top_new);
}
